#pragma once

#include "Defs.h"
#include "Vec3.h"
#include "vec4.h"
#include "Color.h"

const uint screen_w = 800;
const uint screen_h = 600;
const float aspect = (float)screen_w / (float)screen_h;
const float half_w = screen_w * 0.5f;
const float half_h = screen_h * 0.5f;
const float rec_sw = 1.0f / screen_w;
const float rec_sh = 1.0f / screen_h;
const float rec_asp = 1.0f / aspect;

const float4 zero_ps = _mm_setzero_ps();
const float4 one_ps = _mm_set_ps1( 1.0f );
const float4 half_ps = _mm_set_ps1( 0.5f );
const dqword zero_pi = _mm_setzero_si128();

const float pi =      3.141592f;
const float radian =  0.0174533f;
const float degree = 57.2958040f;

const Vec3 X( 1.0f, 0.0f, 0.0f);
const Vec3 Y( 0.0f, 1.0f, 0.0f);
const Vec3 Z( 0.0f, 0.0f, 1.0f);

const Color white = MakeColor( 255, 255, 255 );
const Color black = MakeColor( 0, 0, 0 );
const Color red = MakeColor( 255, 0, 0 );
const Color orange = MakeColor( 255, 128, 0 );
const Color yellow = MakeColor( 255, 255, 0 );
const Color lawn_green = MakeColor( 128, 255, 0 );
const Color green = MakeColor( 0, 255, 0 );
const Color spring_green = MakeColor( 0, 255, 128 );
const Color aqua = MakeColor( 0, 255, 255 );
const Color azure = MakeColor( 0, 128, 255 );
const Color blue = MakeColor( 0, 0, 255 );
const Color violet = MakeColor( 128, 0, 255 );
const Color magenta = MakeColor( 255, 0, 255 );
const Color gray = MakeColor( 128, 128, 128 );
