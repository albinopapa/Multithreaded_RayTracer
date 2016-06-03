#pragma once
#include "Defs.h"
#include <algorithm>

struct Color;

uint GetAlpha( Color C );
uint GetRed( Color C );
uint GetGreen( Color C );
uint GetBlue( Color C );
Color MakeColor( uint R, uint G, uint B, uint A = 255 );
uint Saturate( uint Val );
Color AlphaBlend( Color C0, Color C1 );
Color Avg( Color C0, Color C1 );
uint Brightness( const Color &C );

// test
struct Color
{
	Color operator+( Color C )const;
	Color operator-( Color C )const;
	Color operator*( uint S )const;
	Color operator*( Color C )const;
	Color operator/( uint S )const;
	Color operator/( Color C )const;
	bool operator==( const Color &C );

	uint val = 0;
};
