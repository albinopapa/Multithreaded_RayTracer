#pragma once
#include "Constants.h"
#include <math.h>
#include "Ray.h"
#include "Plane.h"
#include "Sphere.h"

template<class T>
inline T Sq( T Val )
{
	return Val * Val;
}

float ToRadians( float Degree );
float ToDegrees( float Radian );

float Dot3( const Vec4 &V0, const Vec4 &V1 );
float DotProduct( const Vec4 &V0, const Vec4 &V1 );
float SqLength( const Vec4 &V );
float Length( const Vec4 &V );
Vec4 CrossProduct( const Vec4 &V0, const Vec4 &V1 );
Vec4 Normalize( const Vec4 &V );
Vec4 ColorToVec( Color C );
Color VecToColor( const Vec4 &V );
