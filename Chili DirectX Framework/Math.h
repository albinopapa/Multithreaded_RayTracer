#pragma once
#include "Constants.h"
#include <math.h>
#include "Ray.h"
#include "Plane.h"
#include "Sphere.h"
#include "Triangle.h"

template<class T>
inline T Sq( T Val )
{
	return Val * Val;
}

float ToRadians( float Degree );
float ToDegrees( float Radian );

float DotProduct( const Vec3 &V0, const Vec3 &V1 );
float DotProduct( const Vec4 &V0, const Vec4 &V1 );

float SqLength( const Vec3 &V );
float SqLength( const Vec4 &V );

float Length( const Vec3 &V );
float Length( const Vec4 &V );

Vec3 CrossProduct( const Vec3 &V0, const Vec3 &V1 );
Vec4 CrossProduct( const Vec4 &V0, const Vec4 &V1 );

Vec3 Normalize( const Vec3 &V );
Vec4 Normalize( const Vec4 &V );

Vec3 Reflect( const Vec3 &AngleOfInc, const Vec3 &SurfaceNormal );

float FindIntersection( const Ray &Ray_, const Sphere &Sphere_ );
float FindIntersection( const Ray &Ray_, const Plane &Plane_ );
float FindIntersection( const Ray &Ray_, const Triangle &Tri );

Vec4 ColorToVec( Color C );
Color VecToColor( const Vec4 &V );
