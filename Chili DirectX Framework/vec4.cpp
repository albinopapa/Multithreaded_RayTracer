#include "vec4.h"
#include "Vec3.h"

Vec4::Vec4()
	:
	x( 0.0f ),
	y( 0.0f ),
	z( 0.0f ),
	w( 1.0f )
{}

Vec4::Vec4( float X, float Y, float Z, float W )
	:
	x(X),
	y(Y),
	z(Z),
	w(W)
{}

Vec4::Vec4( const Vec3 & V )
	:
	x(V.x),
	y(V.y),
	z(V.z),
	w(1.0f)
{}

Vec4 Vec4::operator+( const Vec4 & V )const
{
	return Vec4(x + V.x, y + V.y, z + V.z);
}

Vec4 Vec4::operator-()const
{
	return Vec4(-x, -y, -z);
}

Vec4 Vec4::operator-( const Vec4 & V )const
{
	return ( *this + (-V) );
}

Vec4 Vec4::operator*( const float S ) const
{
	return Vec4(x * S, y * S, z * S);
}

Vec4 Vec4::operator/( const float S ) const
{
	float recip = 1.0f / S;
	return Vec4(*this * recip);
}
