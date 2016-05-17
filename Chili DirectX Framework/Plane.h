#pragma once
#include "Object.h"
class Plane :
	public Object
{
public:
	Plane();
	Plane( Vec4 &&Norm, float Dist, Color C = gray );
	~Plane();

	float FindIntersection( const Ray &RayInst)override;

	Vec4 normal;
	float distance;
};

