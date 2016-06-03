#pragma once

class alignas( 16 )Vec3
{
public:
	Vec3();
	Vec3( float X, float Y, float Z );

	Vec3 operator+( const Vec3 &V )const;
	Vec3 operator-()const;
	Vec3 operator-( const Vec3 &V )const;
	Vec3 operator*( const float S )const;
	Vec3 operator/( const float S )const;

	float x, y, z;
};

