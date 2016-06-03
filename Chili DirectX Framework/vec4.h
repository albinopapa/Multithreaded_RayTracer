#pragma once

class Vec3;
class alignas( 16 )Vec4
{
public:
	Vec4();
	Vec4( float X, float Y, float Z, float W = 1.0f );
	Vec4( const Vec3 &V );
	
	Vec4 operator+( const Vec4 &V )const;
	Vec4 operator-()const;
	Vec4 operator-( const Vec4 &V )const;
	Vec4 operator*( const float S )const;
	Vec4 operator/( const float S )const;

	float x, y, z, w;
};

