/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	Game.cpp																			  *
 *	Copyright 2011 PlanetChili.net														  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"

Game::Game( HWND hWnd,const KeyboardServer& kServer )
:	gfx ( hWnd ),
	kbd( kServer ),
	cam( {0.0f, 1.5f, -14.0f} ),
	pt_light(Vec4(-7.0f, 10.0f, 10.0f), white),
	sphere(Vec4(Y), 10.0f, green),
	plane(Vec4(Y), 0.0f)	
{
	cam.LookAt( Vec4() );
	obj_list.push_back( &sphere );
	//obj_list.push_back( &plane );
	intersects.reserve( obj_list.size() );

	if( screen_w > screen_h )
	{
		pix_offset_precalc = (float)( screen_w - screen_h ) / ( (float)screen_h * 0.5f );
	}
	else if( screen_h > screen_w )
	{
		pix_offset_precalc = (float)( screen_h - screen_w ) / ( (float)screen_w * 0.5f );
	}

}

void Game::Go()
{
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

int Game::FindClosestObject( const std::vector<float>& Intersects )
{
	int min_index;
	uint intersect_count = Intersects.size();
	if( intersect_count == 0 )
	{
		return -1;
	}
	else if( intersect_count == 1 )
	{
		if( Intersects[ 0 ] >= 0 )
		{
			return 0;
		}
		else
			return -1;
	}
	else 
	{
		float max_val = 0.0f;
		for( const auto &it : Intersects )
		{
			max_val = ( max_val < it ) ? it : max_val;
		}
		/*for( int i = 0; i < intersect_count; ++i )
		{
			if( max_val < Intersects[ i ] )
			{
				max_val = Intersects[ i ];
			}
		}*/
		if( max_val > 0 )
		{
			int i = 0;
			for( const auto &it : Intersects )
			{
				if( it > 0 && it <= max_val )
				{
					max_val = it;
					min_index = i;
				}
				++i;				
			}
			/*for( int i = 0; i < intersect_count; ++i )
			{
				if( Intersects[ i ] > 0 && Intersects[ i ] <= max_val )
				{
					max_val = Intersects[ i ];
					min_index = i;
				}
			}*/

			return min_index;
		}
		else
		{
			return -1;
		}
	}
}

void Game::ComposeFrame()
{
	float rec_sw = 1.0f / screen_w;
	float rec_sh = 1.0f / screen_h;
	float rec_asp = 1.0f / aspect;

	for( int y = 0; y < screen_h; ++y )
	{
		float y_left = ( ( (float)screen_h - y ) + 0.5f ) * rec_sh;

		for( int x = 0; x < screen_w; ++x )
		{
			float x_left = ((float)x + 0.5f) * rec_sw;

			if( screen_w > screen_h )
			{
				x_amount = ( x_left * aspect ) - pix_offset_precalc;
				y_amount = y_left;
			}
			else if( screen_h > screen_w )
			{
				x_amount = x_left;
				y_amount = (y_left * rec_asp ) - pix_offset_precalc;
			}
			else
			{
				x_amount = x_left;
				y_amount = y_left;
			}

			Vec4 ray_dir = Normalize( 
				cam.direction + 
				( cam.right * ( x_amount - 0.5f ) ) + 
				( cam.down * ( y_amount - 0.5f ) ) );

			Ray ray( cam.position, ray_dir );

			if( x == screen_w / 2 && y == screen_h / 2 )
			{
				int a = 0;
			}

			intersects.clear();
			for( int i = 0; i < obj_list.size(); ++i )
			{
				intersects.push_back( obj_list[ i ]->FindIntersection( ray ) );
			}

			int index = FindClosestObject( intersects );
			if( index < 0 )
				continue;

			
			gfx.PutPixel( x, y, obj_list[ index ]->color );
		}
	}
}