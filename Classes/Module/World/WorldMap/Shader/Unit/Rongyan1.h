#pragma once
#include <string>
using namespace std::string_literals; 

namespace Rongyan1 {
  const char *Vert = R"(
    attribute vec4 a_position;
    attribute vec2 a_texCoord;
    attribute vec4 a_color;

    varying vec4 v_fragmentColor;
    varying vec2 v_texCoord;

    void main()
    {
        gl_Position = CC_MVPMatrix * a_position;
        v_fragmentColor = a_color;
        v_texCoord = a_texCoord;
    }
  )";

  const char *Frag = R"(
    #ifdef GL_ES
    precision highp float;
    #endif

    varying vec4 v_fragmentColor;
    varying vec2 v_texCoord;

    uniform sampler2D _rongyan_main;
    uniform sampler2D _niuqu_tex;
    uniform sampler2D _mainzz;

    uniform vec4 _rongyan_main_ST;
    uniform vec4 _niuqu_tex_ST;
    uniform vec4 _mainzz_ST;

    uniform vec4 _rongyan_color;
    uniform float _rongyan_value;
    uniform float _v;
    uniform float _u;
    uniform float _nq_value;
    uniform float _v1;
    uniform float _u1;

    //#define TRANSFORM_TEX(tex,name) (tex.xy * name##_ST.xy + name##_ST.zw) //ST.xy\232\161\168\231\164\186tilling,ST.zw\232\161\168\231\164\186offset
    //#define _Time CC_Time.w
    //i.uv0\229\175\185\229\186\148 v_texCoord 
    //i.vertexColor \229\175\185\229\186\148 a_color

    void main(void) {
        vec4 node_3503 = CC_Time;
        vec2 node_4517 = (_nq_value*((vec2(_u1,_v1)*node_3503.g)+v_texCoord));
        vec4 _niuqu_tex_var = texture2D(_niuqu_tex,(node_4517.xy*_niuqu_tex_ST.xy+_niuqu_tex_ST.zw));
        vec4 node_3118 = CC_Time;
        vec3 node_1332 = (_niuqu_tex_var.rgb+vec3(((vec2(_u,_v)*node_3118.g)+v_texCoord),0.0));
        vec4 _rongyan_main_var = texture2D(_rongyan_main,(node_1332.xy*_rongyan_main_ST.xy+_rongyan_main_ST.zw));
        vec4 _mainzz_var = texture2D(_mainzz,(v_texCoord.xy*_mainzz_ST.xy+_mainzz_ST.zw));
        vec3 emissive = (_rongyan_main_var.rgb*_rongyan_color.rgb*_mainzz_var.rgb*_rongyan_value*v_fragmentColor.a);
        gl_FragColor = vec4(emissive,1.0);
    }
  )"; 
}