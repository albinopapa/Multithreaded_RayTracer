#pragma once
#include "Math.h"

class PointLight
{
public:
	PointLight();
	PointLight( const Vec3 &Pos, const Color &C );
	~PointLight();

	Vec3 position;
	Color color;
};

