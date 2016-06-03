#include "Sphere.h"
#include "Math.h"


Sphere::Sphere()
	:
	radius(1.0f)
{
	color = gray;
}

Sphere::Sphere( const Vec3 &Center, float Rad, Color C )
	:
	center(Center),
	radius(Rad)
{
	color = C;
}


Sphere::~Sphere()
{}

float Sphere::FindIntersection( const Ray & RayInst )
{
	Vec3 ro( RayInst.origin );
	Vec3 rd( RayInst.direction );
	Vec3 sc( center );
	float rad = radius;

	Vec3 ctm( ro - sc );
	float a = 1.0f;
	float b = DotProduct( ctm * 2.0f, rd );
	float c = DotProduct( ctm, ctm ) - Sq( rad );

	float disc = Sq( b ) - ( 4.0f * c );
	float result = -1.0f;

	if( disc <= 0.0f )
	{
		return result;
	}

	float root = ( ( -1.0f * b - sqrtf( disc ) ) * 0.5f );
	result = root > 0.0f ? root : ( sqrtf( disc ) - b ) * 0.5f;

	return result;
}

Vec3 Sphere::GetNormalAt( const Vec3 &Point )const
{
	return Normalize( Point - center );
}
