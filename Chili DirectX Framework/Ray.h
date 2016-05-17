#pragma once
#include "vec4.h"

class Ray
{
public:
	Ray();
	Ray( const Vec4 &Orig, const Vec4 &Dir );
	~Ray();

	Vec4 origin, direction;
};

