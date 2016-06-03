#include "Camera.h"



Camera::Camera()
{}

Camera::Camera( const Vec3 &Position)
	:
	position(Position)
{}


Camera::~Camera()
{}

void Camera::LookAt( const Vec3 &Point )
{
	Vec3 diff( position - Point );
	direction = -Normalize( diff );
	right = Normalize(CrossProduct( Y, direction ));
	down = CrossProduct( right, direction );
}

void Camera::Update()
{
}
