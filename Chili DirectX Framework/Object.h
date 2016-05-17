#pragma once
#include "Ray.h"
#include "Constants.h"

class Object
{
public:
	Object();
	virtual~Object();

	virtual float FindIntersection( const Ray & RayInst ) = 0;

	Color color;
};

