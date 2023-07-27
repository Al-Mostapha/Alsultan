#pragma once
#include <string>
using namespace std::string_literals; 

namespace AllianceTerritoryLineShader {
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

    uniform sampler2D _TileTexture;
    uniform vec4 _Texture_ST;
    uniform vec4 _resolution;
    uniform vec4 _tileInfo;
    uniform float v_lodLevel;
    uniform float step_tile;
    uniform float f_dottedLod;

    float divTileWidth = 0.00390625; // 1/256
    float divTileHeight = 0.0078125; // 1/128
    //const float step_tile = 0.000832639467111; // 1/1201

    vec2 worldPosToUV(vec2 pos)
    {
        return fract(pos.xy/_resolution.xy);
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
        return fract((floor(wp) + 0.5) * step_tile);
    }

    vec3 getTileSpalt(vec2 tp)
    {
        tp = getTileUV(tp);

        vec4 sp = texture2D(_TileTexture, tp);

        return sp.rgb;
    }

    /*
            [Point(-1,-1), 1], #lb
            [Point(0,-1), 2], #b
            [Point(1,-1), 4], #rb
            [Point(-1,0), 8], #l
            [Point(1,0),  16], #r
            [Point(-1,1), 32], #lt
            [Point(0,1),  64], #t
            [Point(1,1),  128], #rt
    */

    float getShowColor(float a)
    {
        float w = 0.9 - v_lodLevel*0.1;
        float lineW = 0.01 * v_lodLevel;
        return max(0.0, a - w) * (1.0/(1.0 - w))*step(a, 1.0-lineW);
    }

    float getShowColor2(float a, float isDottedLine)
    {
        return mix(getShowColor(a), step(0.9, a), isDottedLine);
    }

    float getDottedLineColor(float a)
    {
        return step(mod(floor(a*4.0+0.5), 2.0)+0.5, 1.0);
    }

    const float div_t = 0.0078125; // 1/128 #t(-1,0)
    const float div_b = 0.015625; // 1/64 #b(1,0)
    const float div_l = 0.03125; // 1/32 #l(0,1)
    const float div_r = 0.0625; // 1/16 #r(0,-1)

    const float div_lt = 0.0078125; // 1/128 #lt(-1,1)
    const float div_rt = 0.015625; // 1/64 #rt(-1,-1)
    const float div_lb = 0.03125; // 1/32 #lb(1,1)
    const float div_rb = 0.0625; // 1/16 #rb(1,-1)

    float countAllAlpha(vec2 tp, vec3 sp, float state)
    {
        tp = fract(tp);

        float v1 = .0;
        float a = .0;
        float isDottedLine = step(v_lodLevel, f_dottedLod) * state;

        float r = sp.g * 256.;

        v1 = floor(r * div_t);
        a = max(a, getShowColor2(1.0-tp.x, isDottedLine) * v1 );
        a = mix(a, min(a, getDottedLineColor(tp.y)), isDottedLine);
        r -= v1 * 128.;
        v1 = floor(r * div_b);
        a = max(a, getShowColor2(tp.x, isDottedLine) * v1 );
        a = mix(a, min(a, getDottedLineColor(tp.y)), isDottedLine);
        r -= v1 * 64.;
        v1 = floor(r * div_l);
        a = max(a, getShowColor2(tp.y, isDottedLine) * v1 );
        a = mix(a, min(a, getDottedLineColor(tp.x)), isDottedLine);
        r -= v1 * 32.;
        v1 = floor(r * div_r);
        a = max(a, getShowColor2(1.0-tp.y, isDottedLine) * v1 );
        a = mix(a, min(a, getDottedLineColor(tp.x)), isDottedLine);

        //\232\153\154\231\186\191\228\184\141\232\128\131\232\153\145\229\133\182\228\187\150\229\155\155\228\184\170\230\150\185\229\144\145
        r = sp.b * 256. * step(isDottedLine, 0.5);
        float lineW = 0.01 * v_lodLevel;

        v1 = floor(r * div_lt);
        //a = max(a, getShowColor(tp.y-tp.x) * v1 );
        a = max(a, getShowColor(1.0-tp.x-lineW) * getShowColor(tp.y-lineW) * v1 );
        r -= v1 * 128.;
        v1 = floor(r * div_rt);
        //a = max(a, getShowColor(1.0-tp.x-tp.y) * v1 );
        a = max(a, getShowColor(1.0-tp.x-lineW) * getShowColor(1.0-tp.y-lineW) * v1 );
        r -= v1 * 64.;
        v1 = floor(r * div_lb);
        //a = max(a, getShowColor(tp.x+tp.y-1.0) * v1 );
        a = max(a, getShowColor(tp.x-lineW) * getShowColor(tp.y-lineW) * v1 );
        r -= v1 * 32.;
        v1 = floor(r * div_rb);
        //a = max(a, getShowColor(tp.x-tp.y) * v1 );
        a = max(a, getShowColor(tp.x-lineW) * getShowColor(1.0-tp.y-lineW) * v1 );

        return a; //
    }

    vec3 c1 = vec3(0.0, 1.0, 1.0); //\229\144\140\231\155\159 \233\157\146\232\137\178
    vec3 c2 = vec3(1.0, 1.0, 0.0); //\229\143\139\229\165\189 \233\187\132\232\137\178
    vec3 c3 = vec3(1.0, 0.0, 0.0); //\230\149\140\229\175\185 \231\186\162\232\137\178
    vec3 c4 = vec3(0.0, 0.4941, 1.0); //\232\135\170\229\183\177 \232\147\157\232\137\178
    vec3 c5 = vec3(0.98, 0.98, 0.98); //\230\151\160\229\133\179 \231\153\189\232\137\178
    vec3 c6 = vec3(0.65, 0.65, 0.65); //\230\151\160\228\186\186\229\141\160\233\162\134 \231\129\176\232\137\178

    mat4 colorMat0 = mat4(0.07, 0.44, 0.26, 1,  0.39, 0.78, 0.14, 1,  0.99, 0.81, 0.33, 1,  0.56, 0.16, 0.0, 1);
    mat4 colorMat1 = mat4(0.85, 0.08, 0.9, 1,   0.85, 0.36, 0.27, 1,  0.91, 0.16, 0.46, 1,  0.83, 0.55, 0.01, 1);
    mat4 colorMat2 = mat4(0.38, 0.01, 0.93, 1,  0.55, 0.06, 0.98, 1,  1, 1, 1, 1,  1, 1, 1, 1);

    void main()
    {
        vec2 wp = getSampleUVForWorldPos(_Texture_ST.zw);
        vec2 tp = getTilePos(wp);
        if (tp.x < 0.0 || tp.y < 0.0 || tp.x > _tileInfo.x || tp.y > _tileInfo.y)
        {
            discard;
        }

        vec3 sp = getTileSpalt(tp);
        if (sp.r < 0.0001)
        {
            discard;
        }

        float r = sp.r * 255.0;
        float cIndex = floor(r*0.05);
        r = r-cIndex*20.0;
        float state = step(10.0, r);
        float allianceRelationType = r - state * 10.0;

        //float a = countAllAlpha(wp, sp, state);
        float a = min(1.0, countAllAlpha(tp, sp, state) + step(1.5, v_lodLevel)*0.1);

        //float w1 = step(abs(allianceRelationType - 1.0), 0.1); // 1/255
        //float w2 = step(abs(allianceRelationType - 2.0), 0.1); // 2/255
        //float w3 = step(abs(allianceRelationType - 3.0), 0.1); // 3/255
        //float w4 = step(abs(allianceRelationType - 4.0), 0.1); // 4/255
        //float w5 = step(abs(allianceRelationType - 5.0), 0.1); // 5/255

        //vec3 color = w1 * c1 + w2 * c2 + w3 * c3 + w4 * c4 + w5;

        vec3 colorArray[5];
        colorArray[0] = c1;
        colorArray[1] = c2;
        colorArray[2] = c3;
        colorArray[3] = c4;
        colorArray[4] = c5;
        colorArray[5] = c6;
        vec3 color = colorArray[int(allianceRelationType-0.5)];

            mat4 matArray[3];
            matArray[0] = colorMat0;
            matArray[1] = colorMat1;
            matArray[2] = colorMat2;
        //if (w4+w5 > 0.5 && cIndex > 0.5){
        //if ((w4+w5)*cIndex > 0.5){
        if (allianceRelationType > 3.5 && cIndex > 0.5){
            int _index_i = int(floor((cIndex-0.5)*0.25));
            int _index_j = int(cIndex+0.5) - _index_i*4 - 1;
            color = matArray[_index_i][_index_j].rgb;
        }
        gl_FragColor = vec4(color, 1.0) * a;
    }
  )"; 
}