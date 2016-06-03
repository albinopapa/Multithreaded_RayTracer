#pragma once
#include "Ray.h"
#include "Constants.h"

class Object
{
public:
	Object();
	virtual~Object();

	virtual Vec3 GetNormalAt( const Vec3 &Point_of_Intersection )const = 0;
	virtual float FindIntersection( const Ray & RayInst ) = 0;

	Color color;
};

