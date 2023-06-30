#pragma once

#define X_STRINGIFY(A)  #A
namespace TarrianShader {
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
  uniform sampler2D _TileTexture;\n
  uniform vec4 _Texture_ST;\n
  uniform vec4 _resolution;\n
  uniform vec4 _tileInfo;\n
  uniform vec2 _worldPos;\n
  uniform float _Fade;\n
  \n
  float fixPix = 0.00048828125; 
  float fixPix2 = 0.0009765625;\n
  float divTileWidth = 0.00390625; 
  float divTileHeight = 0.0078125;
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
  vec4 sampleColor(vec2 wp, float mipLevel, float index)\n
  {\n
      mipLevel = floor(clamp(mipLevel, 0., 3.));\n
  \n
      vec2 uv = worldPosToUV(wp, pow(2., mipLevel));\n
  \n
      mipLevel = 0.0;\n
      float size = 1.;\n
      uv = uv * 0.5;\n
  \n
      uv = uv * (1. - fixPix2 );\n
  \n
      float halfSize = 0.5;\n
      float flIndex = floor(index * 0.5);\n
      float offsetX = index * 0.5 - flIndex;\n
      float offsetY = flIndex * halfSize;\n
  \n
      uv.x += offsetX;\n
      uv.y += offsetY;\n
  \n
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
      return mix(lowColor, highColor, mipLevel);\n
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
  #ifdef LOD_FADE\n
      if(_Fade < 1.)\n
      {\n
          vec3 highColor = sampleColor(wp, level - 1., sp).rgb;\n
          color = blendAndFadeTwoLayer(color, highColor, _Fade);\n
      }\n
  #endif\n
      return color;\n
  }\n
  \n
  \n
  void main()\n
  {\n
      vec3 color = getColor(_TileTexture);\n
      gl_FragColor = vec4(color,1.0);\n
  }\n
);
}
