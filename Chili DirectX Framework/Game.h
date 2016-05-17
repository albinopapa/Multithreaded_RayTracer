#pragma once

#include "D3DGraphics.h"
#include "Keyboard.h"
#include "Math.h"
#include "Camera.h"
#include "Light.h"
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"
#include <vector>


class Game
{
public:
	Game( HWND hWnd,const KeyboardServer& kServer );
	void Go();
private:
	int FindClosestObject( const std::vector<float> & Intersects );
	void ComposeFrame();
	/********************************/
	/*  User Functions              */
	// TODO: User functions go here

	/********************************/
private:
	D3DGraphics gfx;
	KeyboardClient kbd;

	Camera cam;
	PointLight pt_light;
	Sphere sphere;
	Plane plane;

	float x_amount, y_amount;
	float pix_offset_precalc;

	std::vector<float> intersects;
	std::vector<Object *> obj_list;
};