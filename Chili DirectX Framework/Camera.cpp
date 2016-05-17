#include "Camera.h"



Camera::Camera()
{}

Camera::Camera( Vec4 && Position)
	:
	position(Position)
{}


Camera::~Camera()
{}

void Camera::LookAt( const Vec4 & Point )
{
	Vec4 diff( position - Point );
	direction = Normalize( -diff );
	down = CrossProduct( Y, direction );
	right = CrossProduct( X, direction );
}

void Camera::Update()
{
}
