#pragma once
#include "Object.h"
class Sphere :
	public Object
{
public:
	Sphere();
	Sphere( const Vec3 &Center, float Rad, Color C );
	~Sphere();
	float FindIntersection( const Ray & RayInst )override;
	Vec3 GetNormalAt( const Vec3 &Point )const override;

	Vec3 center;
	float radius;
};

