#pragma once
#include "Object.h"
class Sphere :
	public Object
{
public:
	Sphere();
	Sphere( Vec4 &&Center, float Rad, Color C );
	~Sphere();
	float FindIntersection( const Ray & RayInst )override;
	Vec4 GetNormalAt( const Vec4 &Point );

	Vec4 center;
	float radius;
};

