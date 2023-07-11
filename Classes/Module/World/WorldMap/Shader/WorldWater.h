#pragma once
#include <string>
using namespace std::string_literals; 

namespace WorldWaterShader {

  const char *Vert = R"(
    attribute vec4 a_position;
    attribute vec2 a_texCoord;
    attribute vec4 a_color;

    varying vec4 v_fragmentColor;
    varying vec2 v_texCoord;
    varying vec2 v_position;

    void main()
    {
        gl_Position = CC_MVPMatrix * a_position;
        gl_Position.z = 0.0;//0.5/gl_Position.w;
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

    uniform float _niuqu_qd;
    uniform float _niuqu1_qd;
    uniform float _niuqu2_qd;
    uniform float _niuqu3_qd;

    uniform float _swater_ld;
    uniform vec4 _water_color;
    uniform vec4 _swater2_color;
    uniform vec4 _swater3_color;

    uniform sampler2D _texture11;
    uniform sampler2D _texture12;
    uniform sampler2D _zhezhao;
    uniform sampler2D _textureall;
    uniform sampler2D _waterMask;

    uniform vec4 _texture11_ST;
    uniform vec4 _texture12_ST;
    uniform vec4 _textureall_ST;
    uniform vec4 _zhezhao_ST;

    uniform vec2 time_uv0; //vec2(_u, _v)*CC_Time.w*3.0 
    uniform vec2 time_uv1; //(vec2(_u2,_v2)*CC_Time.w*3.0)
    uniform vec2 time_uv2; //(vec2(_u3,_v3)*CC_Time.w*3.0)

    //#define TRANSFORM_TEX(tex,name) (tex.xy * name##_ST.xy + name##_ST.zw) //ST.xy\232\161\168\231\164\186tilling,ST.zw\232\161\168\231\164\186offset
    void main(void) {
        vec2 modelCoord = v_texCoord;
        vec4 waterMaskColor = texture2D(_waterMask,mod(modelCoord,1.0));
        if (waterMaskColor.rgb == vec3(0.0,0.0,0.0)){
            discard;
        }else{
            //mat2 testM = mat2( 1.41421 *0.5, -1.41421*0.5*2.0, 1.41421, 1.41421*2.0);//mat2(sqrt(2.0)*0.5, -sqrt(2.0)*0.5, sqrt(2.0), sqrt(2.0));
            //vec2 new_textCoord = mod(testM * (vec2(v_position )/(181.0*10.0)), 1.0);  //v_position + vec2(114.0, 0.0)
            //new_textCoord.y = 2.0 * new_textCoord.y;
            //vec2 new_textCoord = v_texCoord;//\229\142\159\230\160\183
            vec2 new_textCoord;
            float scale = 10.0;
            new_textCoord.x = mod(v_position.x, 256.0 * scale)/(256.0*scale);
            new_textCoord.y = mod(v_position.y, 128.0 * scale)/(128.0*scale);
            //new_textCoord = vec2(0.1, -0.1)*new_textCoord.x + vec2(0.2, 0.2)*new_textCoord.y;
            //new_textCoord.y = mod(1.0-new_textCoord.y, 1.0);
            //new_textCoord.xy = vec2(0.4, 0.4) + new_textCoord*0.2;
            vec4 _texture11_var = texture2D(_texture11,new_textCoord.xy*_texture11_ST.xy + _texture11_ST.zw);
            vec4 _zhezhao_var = texture2D(_zhezhao,new_textCoord.xy*_zhezhao_ST.xy + _zhezhao_ST.zw);
            vec2 offset_texture12 =  _texture11_var.g*_niuqu_qd + time_uv0 + new_textCoord.xy + _zhezhao_var.rg*_niuqu1_qd;
            vec4 _texture12_var = texture2D(_texture12,offset_texture12.xy*_texture12_ST.xy + _texture12_ST.zw);
            vec4 _textureall_var = texture2D(_textureall, new_textCoord.xy * _textureall_ST.xy + _textureall_ST.zw);
            vec2 offset_textureall = time_uv1 +new_textCoord.xy+ vec2(_textureall_var.g*_niuqu2_qd);
            vec4 _textureall_var2 = texture2D(_textureall, offset_textureall.xy * _textureall_ST.xy + _textureall_ST.zw);
            vec2 offset_textureall2 = time_uv2 + new_textCoord.xy+(_textureall_var.g*_niuqu3_qd);
            vec4 _textureall_var3 = texture2D(_textureall, offset_textureall2.xy * _textureall_ST.xy + _textureall_ST.zw);

            //vec3 emissive = (((_water_color.rgb*_texture12_var.r*_swater_ld*_zhezhao_var.rgb)) * v_fragmentColor.a); 
            vec3 emissive = (((_water_color.rgb*_texture12_var.r*_swater_ld*_zhezhao_var.rgb)+(_textureall_var2.r*_swater2_color.rgb)+(_textureall_var3.b*_swater3_color.rgb)) * v_fragmentColor.a); 
            //vec3 emissive = (((_textureall_var2.r*_swater2_color.rgb)+(_textureall_var3.b*_swater3_color.rgb)) * v_fragmentColor.a);
            //vec3 emissive = vec3(new_textCoord, 0.0); //\232\190\147\229\135\186UV\229\157\144\230\160\135\233\162\156\232\137\178
            //vec3 emissive = 0.3 * vec3(1.0, 0.0, 0.0);//\232\190\147\229\135\186\231\186\175\232\137\178
            gl_FragColor = vec4(emissive,waterMaskColor.a);
      }
    }
  )";
}
