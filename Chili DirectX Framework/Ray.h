#pragma once
#include "Vec3.h"

class Ray
{
public:
	Ray();
	Ray( const Vec3 &Orig, const Vec3 &Dir );
	~Ray();

	Vec3 origin, direction;
};

