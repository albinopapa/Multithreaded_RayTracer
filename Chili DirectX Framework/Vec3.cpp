#include "Vec3.h"



Vec3::Vec3()
	:
	x( 0.0f ),
	y( 0.0f ),
	z( 0.0f )
{}

Vec3::Vec3( float X, float Y, float Z )
	:
	x(X),
	y(Y),
	z(Z)
{}

Vec3 Vec3::operator+( const Vec3 & V ) const
{
	return Vec3(x + V.x, y + V.y, z + V.z);
}

Vec3 Vec3::operator-() const
{
	return Vec3(-x, -y, -z);
}

Vec3 Vec3::operator-( const Vec3 & V ) const
{
	return Vec3(x - V.x, y - V.y, z - V.z);
}

Vec3 Vec3::operator*( const float S ) const
{
	return Vec3(x * S, y * S, z * S);
}

Vec3 Vec3::operator/( const float S ) const
{
	return Vec3(x / S, y / S, z / S);
}

