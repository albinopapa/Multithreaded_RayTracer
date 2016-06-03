#pragma once
#include "Object.h"
class Plane :
	public Object
{
public:
	Plane();
	Plane( const Vec3 &Norm, float Dist, Color C = gray );
	~Plane();

	Vec3 GetNormalAt( const Vec3 &Point_of_Intersection )const override;
	float FindIntersection( const Ray &RayInst)override;

	Vec3 normal;
	float distance;
};

