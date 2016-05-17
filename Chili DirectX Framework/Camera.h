#pragma once
#include "Math.h"

class Camera
{
public:
	Camera();
	Camera( Vec4 &&Position);
	~Camera();

	void LookAt( const Vec4 &Point );
	void Update();

	Vec4 position, direction, right, down;
};

