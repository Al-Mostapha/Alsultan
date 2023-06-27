#pragma once

#define X_STRINGIFY(A)  #A
namespace TarrianShader {
const char * Vert = X_STRINGIFY(
  uniform mat4 u_PMatrix;
  attribute vec4 a_position;
  attribute vec2 a_texCoord;
  attribute vec4 a_color;

  uniform vec4 _Texture_ST;

  varying vec4 v_fragmentColor;
  varying vec2 v_texCoord;
  varying vec2 v_position;

  void main()
  {
      gl_Position = u_PMatrix * a_position;
      v_fragmentColor = a_color;
      v_texCoord = a_texCoord;
      v_position = a_position.xy;
  }
);

const char *Freg = X_STRINGIFY(
  \n#ifdef GL_ES\n
    precision highp float;
  \n#endif\n
  varying vec4 v_fragmentColor;
  varying vec2 v_texCoord;
  varying vec2 v_position;
  uniform float v_lodLevel;
  uniform float v_lodControl;

  uniform sampler2D _Texture;
  //uniform sampler2D _SpaltTexture;
  uniform sampler2D _TileTexture;
  //uniform sampler2D _TileTextureLod;
  uniform vec4 _Texture_ST;
  //uniform vec2 u_resolution;
  uniform vec4 _resolution;
  uniform vec4 _tileInfo;
  uniform vec2 _worldPos;
  uniform float _Fade;

  float fixPix = 0.00048828125; //\229\141\149\228\184\170\229\131\143\231\180\160\229\175\185\229\186\148\231\154\132uv\230\152\1750.00048828125
  float fixPix2 = 0.0009765625;
  float divTileWidth = 0.00390625; // 1/256
  float divTileHeight = 0.0078125; // 1/128

  vec2 worldPosToUV( vec2 pos, float tiling)
  {
      vec2 uv = fract(pos.xy/(_resolution.xy * tiling));
      uv.y = 1. - uv.y;
      return uv;
  }

  vec2 getSampleUVForWorldPos(vec2 wp)
  {
      vec2 tmp = v_texCoord.xy;
      tmp.y = 1. - tmp.y;
      vec2 uv = wp.xy + (tmp.xy + _resolution.zw) * _resolution.xy * _Texture_ST.xy;

      return uv;
  }

  vec2 getTilePos(vec2 wp)
  {
      float halfMapSize = _tileInfo.x * 0.5;
      vec2 divPos = vec2(wp.x*divTileWidth, wp.y*divTileHeight);
      float invY = _tileInfo.y - divPos.y;
      return vec2(invY + divPos.x - halfMapSize, invY - divPos.x + halfMapSize);
  }

  vec2 getTileUV(vec2 wp)
  {
      wp.x = fract(wp.x / _tileInfo.x );
      wp.y = fract(wp.y / _tileInfo.y );
      return wp;
  }

  //\230\160\185\230\141\174mipmap\231\186\167\229\136\171\229\146\140\229\155\190\229\157\151\231\180\162\229\188\149\232\191\155\232\161\140\233\135\135\230\160\183
  vec4 sampleColor(vec2 wp, float mipLevel, float index)
  {
      mipLevel = floor(clamp(mipLevel, 0., 3.));

      //\232\189\172\230\141\162uv\229\136\176\229\175\185\229\186\148\231\154\132mipmap\231\186\167\229\136\171
      vec2 uv = worldPosToUV(wp, pow(2., mipLevel));

      mipLevel = 0.0;
      float size = 1.;
      uv = uv * 0.5;

      //\233\152\178\230\173\162\233\187\145\231\186\191\239\188\140\232\174\161\231\174\151\230\140\164\229\135\1862\228\184\170\229\131\143\231\180\160\229\144\142\231\154\132uv\229\157\144\230\160\135
      uv = uv * (1. - fixPix2 );

      //\232\189\172\230\141\162uv\229\136\176\229\155\190\233\155\134\231\186\185\231\144\134\229\157\151
      float halfSize = 0.5;
      float flIndex = floor(index * 0.5);
      float offsetX = index * 0.5 - flIndex;
      float offsetY = flIndex * halfSize;

      uv.x += offsetX;
      uv.y += offsetY;

      //uv\232\176\131\230\149\180 \233\152\178\230\173\162\233\187\145\231\186\191
      uv += fixPix;
      uv.x = clamp(offsetX + fixPix, offsetX + halfSize - fixPix, uv.x);
      uv.y = clamp(offsetY + fixPix, offsetY + halfSize - fixPix, uv.y);

      vec4 terrainColor = texture2D(_Texture, uv);
      return terrainColor;
  }

  float getTileSpalt(vec2 wp,sampler2D tileTexture)
  {
      vec2 tp = getTilePos(wp);
      tp = getTileUV(tp);

      vec4 sp = texture2D(tileTexture, tp);

      float index = sp.r * 4.0; // 255 / 64
      float indexR = floor(index);

      return indexR;
  }

  vec3 blendAndFadeTwoLayer(vec3 lowColor, vec3 highColor, float mipLevel)
  {
      return mix(lowColor, highColor, mipLevel);
  }

  vec3 getColor(sampler2D tileTexture)
  {
      float level = v_lodLevel;

      vec2 wp = getSampleUVForWorldPos(_Texture_ST.zw);
      float sp = getTileSpalt(wp,tileTexture);

      vec3 color = sampleColor(wp, level, sp).rgb;
  \n#ifdef LOD_FADE\n
      if(_Fade < 1.)
      {
          vec3 highColor = sampleColor(wp, level - 1., sp).rgb;
          color = blendAndFadeTwoLayer(color, highColor, _Fade);
      }
  \n#endif\n
      return color;
  }


  void main()
  {
      vec3 color = getColor(_TileTexture);
      gl_FragColor = vec4(color,1.0);
  }
);
}
