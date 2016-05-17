#include "Plane.h"
#include "Math.h"


Plane::Plane()
	:
	normal(Y),
	distance(0.0f)
{
	color = gray;
}

Plane::Plane( Vec4 && Norm, float Dist, Color C )
	:
	normal(Norm),
	distance(Dist)
{
	color = C;
}


Plane::~Plane()
{}

float Plane::FindIntersection( const Ray & RayInst )
{
	float a = Dot3( RayInst.direction, normal );

	if( a == 0.0f )
	{
		return -1.0f;
	}

	float b = Dot3( normal, ( RayInst.origin + ( -( normal * distance ) ) ) );

	return -( b / a );
}
