#pragma once

#define X_STRINGIFY(A)  #A
namespace TarrianShaderLow {
const char * Vert = X_STRINGIFY(
  attribute vec4 a_position;
  attribute vec2 a_texCoord;
  attribute vec4 a_color;

  uniform vec4 _Texture_ST;

  varying vec4 v_fragmentColor;
  varying vec2 v_texCoord;
  varying vec2 v_position;

  void main()
  {
      gl_Position = CC_PMatrix * a_position;
      v_fragmentColor = a_color;
      v_texCoord = a_texCoord;
      v_position = a_position.xy;
  }
);

const char *Freg = X_STRINGIFY(
  #ifdef GL_ES\n
    precision highp float;\n
  #endif\n
  varying vec4 v_fragmentColor;\n
  varying vec2 v_texCoord;\n
  varying vec2 v_position;\n
  uniform float v_lodLevel;\n
  uniform float v_lodControl;\n
  \n
  uniform sampler2D _Texture;\n
  //uniform sampler2D _SpaltTexture;\n
  uniform sampler2D _TileTexture;\n
  uniform sampler2D _TileTextureLod;\n
  uniform vec4 _Texture_ST;\n
  //uniform vec2 u_resolution;\n
  uniform vec4 _resolution;\n
  uniform vec4 _tileInfo;\n
  uniform float _Fade;\n
  \n
  float fixPix = 0.00048828125; //\229\141\149\228\184\170\229\131\143\231\180\160\229\175\185\229\186\148\231\154\132uv\230\152\1750.00048828125\n
  float fixPix2 = 0.0009765625;\n
  float divTileWidth = 0.00390625; // 1/256\n
  float divTileHeight = 0.0078125; // 1/128\n
  \n
  vec2 worldPosToUV( vec2 pos, float tiling)\n
  {\n
      vec2 uv = fract(pos.xy/(_resolution.xy * tiling));\n
      uv.y = 1. - uv.y;\n
      return uv;\n
  }\n
  \n
  vec2 getSampleUVForWorldPos(vec2 wp)\n
  {\n
      vec2 tmp = v_texCoord.xy;\n
      tmp.y = 1. - tmp.y;\n
      vec2 uv = wp.xy + (tmp.xy + _resolution.zw) * _resolution.xy * _Texture_ST.xy;\n
  \n
      return uv;\n
  }\n
  \n
  vec2 getTilePos(vec2 wp)\n
  {\n
      float halfMapSize = _tileInfo.x * 0.5;\n
      vec2 divPos = vec2(wp.x*divTileWidth, wp.y*divTileHeight);\n
      float invY = _tileInfo.y - divPos.y;\n
      return vec2(invY + divPos.x - halfMapSize, invY - divPos.x + halfMapSize);\n
  }\n
  \n
  vec2 getTileUV(vec2 wp)\n
  {\n
      wp.x = fract(wp.x / _tileInfo.x );\n
      wp.y = fract(wp.y / _tileInfo.y );\n
      return wp;\n
  }\n
  \n
  //\230\160\185\230\141\174mipmap\231\186\167\229\136\171\229\146\140\229\155\190\229\157\151\231\180\162\229\188\149\232\191\155\232\161\140\233\135\135\230\160\183\n
  vec4 sampleColor(vec2 wp, float mipLevel, float index)\n
  {\n
      mipLevel = floor(clamp(mipLevel, 0., 3.));\n
  \n
      //\232\189\172\230\141\162uv\229\136\176\229\175\185\229\186\148\231\154\132mipmap\231\186\167\229\136\171\n
      vec2 uv = worldPosToUV(wp, pow(2., mipLevel));\n
  \n
      mipLevel = 0.0;\n
      float size = 1.;\n
      uv = uv * 0.5;\n
  \n
      //\233\152\178\230\173\162\233\187\145\231\186\191\239\188\140\232\174\161\231\174\151\230\140\164\229\135\1862\228\184\170\229\131\143\231\180\160\229\144\142\231\154\132uv\229\157\144\230\160\135\n
      uv = uv * (1. - fixPix2 );\n
  \n
      //\232\189\172\230\141\162uv\229\136\176\229\155\190\233\155\134\231\186\185\231\144\134\229\157\151\n
      float halfSize = 0.5;\n
      float flIndex = floor(index * 0.5);\n
      float offsetX = index * 0.5 - flIndex;\n
      float offsetY = flIndex * halfSize;\n
  \n
      uv.x += offsetX;\n
      uv.y += offsetY;\n
  \n
      //uv\232\176\131\230\149\180 \233\152\178\230\173\162\233\187\145\231\186\191\n
      uv += fixPix;\n
      uv.x = clamp(offsetX + fixPix, offsetX + halfSize - fixPix, uv.x);\n
      uv.y = clamp(offsetY + fixPix, offsetY + halfSize - fixPix, uv.y);\n
  \n
      vec4 terrainColor = texture2D(_Texture, uv);\n
      return terrainColor;\n
  }\n
  \n
  float getTileSpalt(vec2 wp,sampler2D tileTexture)\n
  {\n
      vec2 tp = getTilePos(wp);\n
      tp = getTileUV(tp);\n
  \n
      vec4 sp = texture2D(tileTexture, tp);\n
  \n
      float index = sp.r * 4.0; // 255 / 64\n
      float indexR = floor(index);\n
  \n
      return indexR;\n
  }\n
  \n
  vec3 blendAndFadeTwoLayer(vec3 lowColor, vec3 highColor, float mipLevel)\n
  {\n
      return mix(lowColor, highColor, fract(mipLevel));\n
  }\n
  \n
  vec3 getColor(sampler2D tileTexture)\n
  {\n
      float level = v_lodLevel;\n
  \n
      vec2 wp = getSampleUVForWorldPos(_Texture_ST.zw);\n
      float sp = getTileSpalt(wp,tileTexture);\n
  \n
      vec3 color = sampleColor(wp, level, sp).rgb;\n
      vec3 highColor = sampleColor(wp, level - 1., sp).rgb;\n
      color = blendAndFadeTwoLayer(color, highColor, level);\n
  \n
      return color;\n
  }\n
  \n
  vec3 getLodColor()\n
  {\n
      float level = v_lodLevel;\n
      vec2 wp = getSampleUVForWorldPos(_Texture_ST.zw);\n
      float sp = getTileSpalt(wp,_TileTextureLod);\n
      vec3 color = sampleColor(wp, level, sp).rgb;\n
  \n
      //vec3 highColor = sampleColor(wp, level - 1., sp.r).rgb;\n
      //color = blendAndFadeTwoLayer(color, highColor, level);\n
      return color;\n
  }\n
  \n
  void main()\n
  {\n
      float level = v_lodLevel;\n
      vec2 wp = getSampleUVForWorldPos(_Texture_ST.zw);\n
      float spLod = getTileSpalt(wp,_TileTextureLod);\n
      vec3 color = sampleColor(wp, level, spLod).rgb;\n
  \n
      float sp = getTileSpalt(wp,_TileTexture);\n
      vec3 colorOut = sampleColor(wp, level, sp).rgb;\n
      color = blendAndFadeTwoLayer(color, colorOut, _Fade);\n
      gl_FragColor = vec4(color,1.0);\n
  }\n
);
}
