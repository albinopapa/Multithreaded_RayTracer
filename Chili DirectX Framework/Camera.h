#pragma once
#include "Math.h"

class Camera
{
public:
	Camera();
	Camera( const Vec3 &Position);
	~Camera();

	void LookAt( const Vec3 &Point );
	void Update();

	Vec3 position, direction, right, down;
};

