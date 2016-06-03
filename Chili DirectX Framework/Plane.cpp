#include "Plane.h"
#include "Math.h"


Plane::Plane()
	:
	normal(Y),
	distance(0.0f)
{
	color = gray;
}

Plane::Plane( const Vec3 &Norm, float Dist, Color C )
	:
	normal(Norm),
	distance(Dist)
{
	color = C;
}


Plane::~Plane()
{}

Vec3 Plane::GetNormalAt( const Vec3 & Point_of_Intersection )const
{
	return normal;
}

float Plane::FindIntersection( const Ray & RayInst )
{
	Vec3 ro( RayInst.origin );
	Vec3 rd( RayInst.direction );
	Vec3 pn( normal );
	float pd = distance;

	float a = DotProduct( rd, pn );

	if( a == 0.0f )
	{
		return -1.0f;
	}

	float b = DotProduct( pn, ( ro - ( pn * pd ) ) );

	return -( b / a );
}
