/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	D3DGraphics.cpp																		  *
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
#include "D3DGraphics.h"

D3DGraphics::D3DGraphics( HWND hWnd )
{
	pDirect3D = Direct3DCreate9( D3D_SDK_VERSION );

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp,sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

    pDirect3D->CreateDevice( D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,&d3dpp,&pDevice );

	pDevice->GetBackBuffer( 0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer );

	pSysBuffer = new uint[ screen_w * screen_h ];
}

D3DGraphics::~D3DGraphics()
{
	pBackBuffer->Release();
	if( pDevice )
	{
		pDevice->Release();
		pDevice = NULL;
	}
	if( pDirect3D )
	{
		pDirect3D->Release();
		pDirect3D = NULL;
	}
}

void D3DGraphics::PutPixel( int x,int y,int r,int g,int b )
{
	pSysBuffer[ x + ( y * screen_w ) ] = MakeColor( r, g, b ).val;
}

void D3DGraphics::PutPixel( int X, int Y, Color C )
{
	pSysBuffer[ X + ( Y * screen_w ) ] = C.val;
}

void D3DGraphics::BeginFrame()
{
	memset( pSysBuffer, 0, sizeof( uint ) * screen_w * screen_h );
}

void D3DGraphics::EndFrame()
{
	pBackBuffer->LockRect( &rect, NULL, NULL );
	
	
	for( int y = 0; y < screen_h; ++y )
	{
		int row_offset = y * screen_w;
		uint* vid_it = &( (uint*)rect.pBits )[ row_offset ];
		uint* sys_it = &( pSysBuffer[ row_offset ] );
		
		memcpy( vid_it, sys_it, sizeof( uint ) * screen_w );
	}

	pBackBuffer->UnlockRect();
	pDevice->Present( NULL,NULL,NULL,NULL );
}
