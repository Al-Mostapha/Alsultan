#pragma once
#include <string>
using namespace std::string_literals; 

namespace FogNormalShader {
  const char *Vert = R"(
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
  )";

  const char *Frag = R"(
    #ifdef GL_ES
    precision highp float;
    #endif
    varying vec4 v_fragmentColor;
    varying vec2 v_texCoord;
    varying vec2 v_position;

    uniform sampler2D _Texture;
    uniform vec4 _Texture_ST;
    uniform vec4 _resolution;
    uniform vec4 _tileInfo;
    uniform float _mapScale;
    uniform float _mapScale_next;
    uniform float _mapLevel;
    uniform vec4 _fogRect;

    float divTileWidth = 0.00390625; // 1/256
    float divTileHeight = 0.0078125; // 1/128

    vec2 worldPosToUV(vec2 pos, float mapScale)
    {
        return fract(pos.xy/(_resolution.xy*mapScale));
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

    vec4 sampleColor(vec2 uv)
    {
        vec4 color = texture2D(_Texture, uv + vec2(fract(CC_Time.x*0.5), 0.0));
        return color;
    }

    vec4 blendAndFadeTwoLayer(vec4 lowColor, vec4 highColor, float mipLevel)
    {
        return mix(lowColor, highColor, fract(mipLevel));
    }

    void main()
    {   
        vec2 wp = getSampleUVForWorldPos(_Texture_ST.zw);
        vec2 tp = getTilePos(wp);
        vec2 floorTp = floor(tp + 0.001);
        if (floorTp.x < _fogRect.x || floorTp.y < _fogRect.y || floorTp.x > _fogRect.z || floorTp.y > _fogRect.w)
        {
            discard;
        }

        float mapLevel = floor(_mapLevel);
        
        vec2 uv1 = worldPosToUV(wp, _mapScale);
        vec4 lowColor = sampleColor(uv1);

        vec2 uv2 = worldPosToUV(wp, _mapScale_next);
        vec4 highColor = sampleColor(uv2);

        vec4 color = blendAndFadeTwoLayer(lowColor, highColor, _mapLevel);

        float a = 1.0;
        float v = 0.0;
        float x = 1.0;
        float y = 0.0;
    /*
        if (tp.x < _fogRect.x + _mapScale)
        {
            a *= (tp.x - _fogRect.x)/_mapScale;
        }
        if (tp.y < _fogRect.y + _mapScale)
        {
            a *= (tp.y - _fogRect.y)/_mapScale;
        }
        if (tp.x > _fogRect.z - _mapScale + 1.0)
        {
            a *= (1.0 - tp.x + _fogRect.z)/_mapScale;
        }
        if (tp.y > _fogRect.w - _mapScale + 1.0)
        {
            a *= (1.0 - tp.y + _fogRect.w)/_mapScale;
        }
    */
        v = step(tp.x, _fogRect.x + mapLevel);
        y = (tp.x - _fogRect.x)/mapLevel;
        a *= mix(x, y, v);

        v = step(tp.y, _fogRect.y + mapLevel);
        y = (tp.y - _fogRect.y)/mapLevel;
        a *= mix(x, y, v);

        v = step(_fogRect.z - mapLevel + 1.0, tp.x);
        y = (1.0 - tp.x + _fogRect.z)/mapLevel;
        a *= mix(x, y, v);

        v = step(_fogRect.w - mapLevel + 1.0, tp.y);
        y = (1.0 - tp.y + _fogRect.w)/mapLevel;
        a *= mix(x, y, v);

        color.a *= a;
        color.rgb *= a;
        
        gl_FragColor = color;
    }
  )"; 
}