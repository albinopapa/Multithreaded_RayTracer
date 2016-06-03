#pragma once

#include "D3DGraphics.h"
#include "Keyboard.h"
#include "Timer.h"

#include "Math.h"
#include "Camera.h"
#include "Light.h"
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"

#include <thread>
#include <atomic>
#include <condition_variable>
#include <vector>


class Game
{
public:
	Game( HWND WinHandle,const KeyboardServer& kServer );
	~Game();
	void Go();

private:
	void Game::RunThreads(int Tid);
	int RenderImage(const float XOff, const float YOff, std::vector<float> &Intersects);
	int FindClosestObject( const std::vector<float> & Intersects );
	void CheckIn();
	Color GetColorAt(const Vec3 &Point_of_Intersection, const Vec3 &Direction_of_Intersection,
		const std::vector<Object *> &ObjectList, const uint32_t Index, const PointLight &Pt_Light,
		std::vector<float> &ShadowIntersectionDistance, const float AmbientValue);
	void ComposeFrame();
	/********************************/
	/*  User Functions              */
private:
	D3DGraphics gfx;
	KeyboardClient kbd;
	Timer t;
	HWND hWnd;

	Camera cam;
	PointLight pt_light;
	Sphere sphere;
	Plane plane;

	float x_amount, y_amount;
	float pix_offset_precalc;
	float ambient;

	std::vector<Object *> obj_list;
	std::vector<std::thread> threads;
	std::mutex mtx;
	std::condition_variable worker, boss;
	BOOL ready = FALSE;
	BOOL thread_exit = FALSE;
	int tid, nThreads;
	std::atomic<int> num_waiting;

	/********************************/
};