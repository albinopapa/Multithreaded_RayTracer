#include "Math.h"

float ToRadians( float Degree )
{
	return Degree * radian;
}

float ToDegrees( float Radian )
{
	return Radian * degree;
}

float DotProduct( const Vec3 &V0, const Vec3 &V1 )
{
	return ( V0.x * V1.x ) + ( V0.y * V1.y ) + ( V0.z * V1.z );
}

float DotProduct( const Vec4 & V0, const Vec4 & V1 )
{
	return ( V0.x * V1.x ) + ( V0.y * V1.y ) + ( V0.z * V1.z ) + ( V0.w * V1.w );
}

float SqLength( const Vec3 & V )
{
	return DotProduct( V, V );
}

float SqLength( const Vec4 & V )
{
	return DotProduct( V, V );
}

float Length( const Vec3 & V )
{
	return sqrtf( SqLength( V ) );
}

float Length( const Vec4 & V )
{
	return sqrtf( SqLength( V ) );
}

Vec3 CrossProduct( const Vec3 & V0, const Vec3 & V1 )
{
	Vec3 res;
	res.x = ( V0.y * V1.z ) - ( V0.z * V1.y );
	res.y = ( V0.z * V1.x ) - ( V0.x * V1.z );
	res.z = ( V0.x * V1.y ) - ( V0.y * V1.x );

	return res;
}

Vec4 CrossProduct( const Vec4 & V0, const Vec4 & V1 )
{
	Vec4 res;
	res.x = ( V0.y * V1.z ) - ( V0.z * V1.y );
	res.y = ( V0.z * V1.w ) - ( V0.w * V1.z );
	res.z = ( V0.w * V1.x ) - ( V0.x * V1.w );
	res.w = ( V0.x * V1.y ) - ( V0.y * V1.x );

	return res;
}

Vec3 Normalize( const Vec3 & V )
{
	float recip = 1.0f / Length( V );
	return Vec3( V * recip );
}

Vec4 Normalize( const Vec4 & V )
{
	float recip = 1.0f / Length( V );
	return Vec4(V * recip);
}

Vec3 Reflect( const Vec3 & AngleOfInc, const Vec3 & SurfaceNormal )
{
	return ( AngleOfInc - ( SurfaceNormal * DotProduct( AngleOfInc, SurfaceNormal ) * 2.0f ) );
}

float FindIntersection( const Ray & Ray_, const Sphere & Sphere_ )
{
	Vec3 ro( Ray_.origin );
	Vec3 rd( Ray_.direction );
	Vec3 sc( Sphere_.center );
	float radius = Sphere_.radius;
	
	Vec3 ctm( ro - sc );
	float a = 1.0f;
	float b = DotProduct( ctm * 2.0f, rd );
	float c = DotProduct( ctm, ctm ) - Sq( radius );

	float disc = Sq( b ) - ( 4.0f * c );
	float result = -1.0f;
	if( disc <= 0.0f )
	{
		return result;
	}

	float root = ( ( -1.0f * b - sqrtf( disc ) ) * 0.5f );
	result = root > 0.0f ? root : ( sqrtf( disc ) - b ) * 0.5f;

	return result;
}

float FindIntersection( const Ray & Ray_, const Plane & Plane_ )
{
	Vec3 ro( Ray_.origin );
	Vec3 rd( Ray_.direction );
	Vec3 pn( Plane_.normal );
	float pd = Plane_.distance;

	float a = DotProduct( rd, pn);

	if( a == 0.0f )
	{
		return -1.0f;
	}

	float b = DotProduct( pn, ( ro - ( pn * pd ) ) );

	return -( b / a );
}

float FindIntersection( const Ray & Ray_, const Triangle & Tri )
{
	return 0.0f;
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
