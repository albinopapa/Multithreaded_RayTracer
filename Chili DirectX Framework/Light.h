#pragma once
#include "Math.h"

class PointLight
{
public:
	PointLight();
	PointLight( Vec4 &&Pos, Color C );
	~PointLight();

	Vec4 position;
	Color color;
};

