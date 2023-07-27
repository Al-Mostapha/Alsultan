#pragma once
#include <string>
using namespace std::string_literals; 

namespace AllianceTerritoryDrawShader {
  const char *Vert = R"(
    attribute vec4 a_position;
    attribute vec2 a_texCoord;
    attribute vec4 a_color;

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

    uniform sampler2D _TileTexture;
    uniform float step_tile;

    vec4 sampleColor(vec2 uv)
    {
        vec4 color1 = texture2D(_TileTexture, uv);
        return color1;
    }

    const float mul_t = 0.50196; // 128/255 #t(-1,0)
    const float mul_b = 0.25098; // 64/255 #b(1,0)
    const float mul_l = 0.12549; // 32/255 #l(0,1)
    const float mul_r = 0.062745; // 16/255 #r(0,-1)

    const float mul_lt = 0.50196; // 128/255 #lt(-1,1)
    const float mul_rt = 0.25098; // 64/255 #rt(-1,-1)
    const float mul_lb = 0.12549; // 32/255 #lb(1,1)
    const float mul_rb = 0.062745; // 16/255 #rb(1,-1)

    //const float step_tile = 0.000832639467111; // 1/1201
    //const float step_tile = 1.0/600.0;

    float getLeagueID(vec4 color)
    {
        return color.g * 256.0 + color.b;
    }

    float getActivityState(float r)
    {
        return step(10.0, r*256.0);
    }

    float getDirColor(vec4 curColor, vec2 dir, float weight)
    {
        vec2 uv = v_texCoord;
        vec4 color = sampleColor(uv + dir*step_tile);
        float leagueID = getLeagueID(curColor);
        //float state = getActivityState(curColor.r);
        float newLeagueID = getLeagueID(color);
        //float newState = getActivityState(color.r);

        //float a = step(abs(newLeagueID - leagueID), 0.0001) * step(abs(newState - state), 0.0001);
        //return (1.0-a) * weight;
        return step(0.0001, abs(newLeagueID - leagueID)) * weight;
    }

    void main()
    {   
        vec2 uv = v_texCoord;

        vec4 color = sampleColor(uv);
        float leagueID = getLeagueID(color);
        if (leagueID < 0.0001)
        {
            discard;
        }

        vec3 ret = vec3(0);
        ret.r = color.r; //\232\174\176\229\189\149\228\184\128\228\184\139\232\129\148\231\155\159\229\133\179\231\179\187

        ret.g += getDirColor(color, vec2(-1, 0), mul_t);
        ret.g += getDirColor(color, vec2(1, 0), mul_b);
        ret.g += getDirColor(color, vec2(0, 1), mul_l);
        ret.g += getDirColor(color, vec2(0, -1), mul_r);

        ret.b += getDirColor(color, vec2(-1, 1), mul_lt);
        ret.b += getDirColor(color, vec2(-1, -1), mul_rt);
        ret.b += getDirColor(color, vec2(1, 1), mul_lb);
        ret.b += getDirColor(color, vec2(1, -1), mul_rb);
        
        gl_FragColor = vec4(ret, 1.0);
    }
  )"; 
}