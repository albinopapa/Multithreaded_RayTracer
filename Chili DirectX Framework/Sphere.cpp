#include "Sphere.h"
#include "Math.h"


Sphere::Sphere()
	:
	radius(1.0f)
{
	color = gray;
}

Sphere::Sphere( Vec4 && Center, float Rad, Color C )
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
	Vec4 ro( RayInst.origin );
	Vec4 rd( RayInst.direction );
	Vec4 ctm( center - ro);
	Vec4 b_ctm( ctm * 2.0f );
	float a = 1.0f;
	float b = Dot3( b_ctm, rd );
	float c = Dot3( ctm, ctm ) - Sq( radius );

	float disc = Sq( b ) - ( 4.0f * c );
	if( disc >= 0.0f )
	{
		float root = ( ( -b - sqrtf( disc ) ) * 0.5f );
		if( root > 0.0f )
		{
			return root;
		}
		else
		{
			root = ( sqrtf( disc ) - b ) * 0.5f;
			return root;
		}
	}

	return -1.0f;
}

Vec4 Sphere::GetNormalAt( const Vec4 & Point )
{
	return Normalize( Point - center );
}
