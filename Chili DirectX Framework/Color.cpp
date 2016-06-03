#include "Color.h"

using namespace std;

uint GetAlpha( Color C )
{
	return ( C.val & 0xFF000000 ) >> 24;
}

uint GetRed( Color C )
{
	return ( C.val & 0x00FF0000 ) >> 16;
}

uint GetGreen( Color C )
{
	return ( C.val & 0x0000FF00 ) >> 8;
}

uint GetBlue( Color C )
{
	return ( C.val & 0x000000FF );
}

Color MakeColor( uint R, uint G, uint B, uint A )
{
	Color c;
	c.val = ( A << 24 ) | ( R << 16 ) | ( G << 8 ) | B;
	return c;
}

uint Saturate( uint Val )
{
	return min( 255, max( 0, (int)Val ) );
}

Color AlphaBlend( Color C0, Color C1 )
{
	uint sa = GetAlpha( C0 );
	uint da = 255 - sa;

	uint sr = GetRed(C0);
	uint sg = GetGreen(C0);
	uint sb = GetBlue(C0);

	uint dr = GetRed(C1);
	uint dg = GetGreen(C1);
	uint db = GetBlue(C1);
	
	uint rr = ( ( sr * sa ) + ( dr * da ) >> 8 ) + 1;
	uint rg = ( ( sg * sa ) + ( dg * da ) >> 8 ) + 1;
	uint rb = ( ( sb * sa ) + ( db * da ) >> 8 ) + 1;

	return MakeColor( rr, rg, rb );
}

Color Avg( Color C0, Color C1 )
{
	uint ra = ( GetAlpha( C0 ) + GetAlpha( C1 ) ) >> 1;
	uint rr = ( GetRed( C0 ) + GetRed( C1 ) ) >> 1;
	uint rg = ( GetGreen( C0 ) + GetGreen( C1 ) ) >> 1;
	uint rb = ( GetBlue( C0 ) + GetBlue( C1 ) ) >> 1;
	return MakeColor( rr, rg, rb, ra );
}

uint Brightness( const Color & C )
{
	auto r = GetRed( C );
	auto g = GetGreen( C );
	auto b = GetBlue( C );
	return ( r + g + b ) / 3;
}

Color Color::operator+( Color C ) const
{
	uint r = Saturate( GetRed( *this ) + GetRed( C ) );
	uint g = Saturate( GetGreen( *this ) + GetRed( C ) );
	uint b = Saturate( GetBlue( *this ) + GetBlue( C ) );
	
	return MakeColor( r, g, b );
}

Color Color::operator-( Color C ) const
{
	uint r = Saturate( GetRed( *this )	 - GetRed( C ) );
	uint g = Saturate( GetGreen( *this ) - GetRed( C ) );
	uint b = Saturate( GetBlue( *this )  - GetBlue( C ) );

	return MakeColor( r, g, b );
}

Color Color::operator*( uint S ) const
{
	Color c = MakeColor( S, S, S );

	return (*this * c);
}

Color Color::operator*( Color C ) const
{
	uint r = (GetRed( *this )   * GetRed( C ) ) >> 8;
	uint g = (GetGreen( *this ) * GetRed( C ) ) >> 8;
	uint b = (GetBlue( *this )  * GetBlue( C ) ) >> 8;

	return MakeColor( r, g, b );
}

Color Color::operator/( uint S ) const
{
	Color c = MakeColor( S, S, S );

	return ( *this / c );
}

Color Color::operator/( Color C ) const
{
	uint dr = max( GetRed( C ), 1U );
	uint dg = max( GetGreen( C ), 1U );
	uint db = max( GetBlue( C ), 1U );

	uint r = Saturate( ( GetRed( *this ) << 8 ) / dr );
	uint g = Saturate( ( GetGreen( *this ) << 8 ) / dg );
	uint b = Saturate( ( GetBlue( *this ) << 8) / db );

	return MakeColor( r, g, b );
}

bool Color::operator==( const Color & C )
{
	bool same = GetRed( *this ) == GetRed( C ) &&
		GetGreen( *this ) == GetGreen( C ) &&
		GetBlue( *this ) == GetBlue( C );

	return same;
}
