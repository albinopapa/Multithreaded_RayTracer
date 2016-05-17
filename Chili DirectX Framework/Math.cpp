#include "Math.h"

float ToRadians( float Degree )
{
	return Degree * radian;
}

float ToDegrees( float Radian )
{
	return Radian * degree;
}

float Dot3( const Vec4 &V0, const Vec4 &V1 )
{
	return ( V0.x * V1.x ) + ( V0.y * V1.y ) + ( V0.z * V1.z );
}

float DotProduct( const Vec4 & V0, const Vec4 & V1 )
{
	return ( V0.x * V1.x ) + ( V0.y * V1.y ) + ( V0.z * V1.z ) + ( V0.w * V1.w );
}

float SqLength( const Vec4 & V )
{
	return DotProduct( V, V );
}

float Length( const Vec4 & V )
{
	return sqrtf( SqLength( V ) );
}

Vec4 CrossProduct( const Vec4 & V0, const Vec4 & V1 )
{
	Vec4 res;
	res.x = ( V0.y * V1.z ) - ( V0.z * V1.y );
	res.y = ( V0.z * V1.x ) - ( V0.x * V1.z );
	res.z = ( V0.x * V1.y ) - ( V0.y * V1.x );

	return res;
}

Vec4 Normalize( const Vec4 & V )
{
	float recip = 1.0f / Length( V );
	return Vec4(V * recip);
}

Vec4 ColorToVec( Color C )
{
	return Vec4( GetRed( C ), GetGreen( C ), GetBlue( C ), GetAlpha( C ) );
}

Color VecToColor( const Vec4 & V )
{
	Vec4 temp( V * 255.0f );
	
	return MakeColor( (uint)temp.x, (uint)temp.y, (uint)temp.z, (uint)temp.w );
}
