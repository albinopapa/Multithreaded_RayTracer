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
#include <string>
#include <sstream>


Game::Game( HWND WinHandle, const KeyboardServer& kServer )
	: gfx( WinHandle ),
	kbd( kServer ),
	hWnd( WinHandle ),
	cam( {3.0f, 1.5f, -4.0f} ),
	pt_light( Vec3( -7.0f, 10.0f, 10.0f ), white ),
	sphere( Vec3(), 1.0f, green ),
	plane( Y, -1.0f ),
	nThreads(3),
	num_waiting(0),
	ambient(0.2f)
{
	cam.LookAt( Vec3() );
	obj_list.push_back( &sphere );
	obj_list.push_back( &plane );

	if( screen_w > screen_h )
	{
		pix_offset_precalc = ( (float)( screen_w - screen_h ) / (float)screen_h ) * 0.5f;
	}
	else if( screen_h > screen_w )
	{
		pix_offset_precalc = ( (float)( screen_h - screen_w ) / (float)screen_w ) * 0.5f;
	}

	for( int i = 0; i < nThreads; ++i )
	{
		threads.push_back( std::thread( &Game::RunThreads, this, i ) );
	}

}

Game::~Game()
{
	std::unique_lock<std::mutex> lck( mtx );
	thread_exit = true;
	worker.notify_all();
	boss.wait( lck );

	for( int i = 0; i < nThreads; ++i )
	{
		threads[ i ].join();
	}
}

void Test()
{

	/*typedef __m256d mdouble;

	const byte mask000 = 0b00000000;
	const byte mask001 = 0b00000001;
	const byte mask002 = 0b00000010;
	const byte mask003 = 0b00000011;
	const byte mask004 = 0b00000100;
	const byte mask005 = 0b00000101;
	const byte mask006 = 0b00000110;
	const byte mask007 = 0b00000111;
	const byte mask008 = 0b00001000;
	const byte mask009 = 0b00001001;
	const byte mask010 = 0b00001010;
	const byte mask011 = 0b00001011;
	const byte mask012 = 0b00001100;
	const byte mask013 = 0b00001101;
	const byte mask014 = 0b00001110;
	const byte mask015 = 0b00001111;
	const byte mask016 = 0b00010000;
	const byte mask017 = 0b00010001;
	const byte mask018 = 0b00010010;
	const byte mask019 = 0b00010011;
	const byte mask020 = 0b00010100;
	const byte mask021 = 0b00010101;
	const byte mask022 = 0b00010110;
	const byte mask023 = 0b00010111;
	const byte mask024 = 0b00011000;
	const byte mask025 = 0b00011001;
	const byte mask026 = 0b00011010;
	const byte mask027 = 0b00011011;
	const byte mask028 = 0b00011100;
	const byte mask029 = 0b00011101;
	const byte mask030 = 0b00011110;
	const byte mask031 = 0b00011111;
	const byte mask032 = 0b00100000;
	const byte mask033 = 0b00100001;
	const byte mask034 = 0b00100010;
	const byte mask035 = 0b00100011;
	const byte mask036 = 0b00100100;
	const byte mask037 = 0b00100101;
	const byte mask038 = 0b00100110;
	const byte mask039 = 0b00100111;
	const byte mask040 = 0b00101000;
	const byte mask041 = 0b00101001;
	const byte mask042 = 0b00101010;
	const byte mask043 = 0b00101011;
	const byte mask044 = 0b00101100;
	const byte mask045 = 0b00101101;
	const byte mask046 = 0b00101110;
	const byte mask047 = 0b00101111;
	const byte mask048 = 0b00110000;
	const byte mask049 = 0b00110001;
	const byte mask050 = 0b00110010;
	const byte mask051 = 0b00110011;
	const byte mask052 = 0b00110100;
	const byte mask053 = 0b00110101;
	const byte mask054 = 0b00110110;
	const byte mask055 = 0b00110111;
	const byte mask056 = 0b00111000;
	const byte mask057 = 0b00111001;
	const byte mask058 = 0b00111010;
	const byte mask059 = 0b00111011;
	const byte mask060 = 0b00111100;
	const byte mask061 = 0b00111101;
	const byte mask062 = 0b00111110;
	const byte mask063 = 0b00111111;
	const byte mask064 = 0b01000000;
	const byte mask065 = 0b01000001;
	const byte mask066 = 0b01000010;
	const byte mask067 = 0b01000011;
	const byte mask068 = 0b01000100;
	const byte mask069 = 0b01000101;
	const byte mask070 = 0b01000110;
	const byte mask071 = 0b01000111;
	const byte mask072 = 0b01001000;
	const byte mask073 = 0b01001001;
	const byte mask074 = 0b01001010;
	const byte mask075 = 0b01001011;
	const byte mask076 = 0b01001100;
	const byte mask077 = 0b01001101;
	const byte mask078 = 0b01001110;
	const byte mask079 = 0b01001111;
	const byte mask080 = 0b01010000;
	const byte mask081 = 0b01010001;
	const byte mask082 = 0b01010010;
	const byte mask083 = 0b01010011;
	const byte mask084 = 0b01010100;
	const byte mask085 = 0b01010101;
	const byte mask086 = 0b01010110;
	const byte mask087 = 0b01010111;
	const byte mask088 = 0b01011000;
	const byte mask089 = 0b01011001;
	const byte mask090 = 0b01011010;
	const byte mask091 = 0b01011011;
	const byte mask092 = 0b01011100;
	const byte mask093 = 0b01011101;
	const byte mask094 = 0b01011110;
	const byte mask095 = 0b01011111;
	const byte mask096 = 0b01100000;
	const byte mask097 = 0b01100001;
	const byte mask098 = 0b01100010;
	const byte mask099 = 0b01100011;
	const byte mask100 = 0b01100100;
	const byte mask101 = 0b01100101;
	const byte mask102 = 0b01100110;
	const byte mask103 = 0b01100111;
	const byte mask104 = 0b01101000;
	const byte mask105 = 0b01101001;
	const byte mask106 = 0b01101010;
	const byte mask107 = 0b01101011;
	const byte mask108 = 0b01101100;
	const byte mask109 = 0b01101101;
	const byte mask110 = 0b01101110;
	const byte mask111 = 0b01101111;
	const byte mask112 = 0b01110000;
	const byte mask113 = 0b01110001;
	const byte mask114 = 0b01110010;
	const byte mask115 = 0b01110011;
	const byte mask116 = 0b01110100;
	const byte mask117 = 0b01110101;
	const byte mask118 = 0b01110110;
	const byte mask119 = 0b01110111;
	const byte mask120 = 0b01111000;
	const byte mask121 = 0b01111001;
	const byte mask122 = 0b01111010;
	const byte mask123 = 0b01111011;
	const byte mask124 = 0b01111100;
	const byte mask125 = 0b01111101;
	const byte mask126 = 0b01111110;
	const byte mask127 = 0b01111111;
	const byte mask128 = 0b10000000;
	const byte mask129 = 0b10000001;
	const byte mask130 = 0b10000010;
	const byte mask131 = 0b10000011;
	const byte mask132 = 0b10000100;
	const byte mask133 = 0b10000101;
	const byte mask134 = 0b10000110;
	const byte mask135 = 0b10000111;
	const byte mask136 = 0b10001000;
	const byte mask137 = 0b10001001;
	const byte mask138 = 0b10001010;
	const byte mask139 = 0b10001011;
	const byte mask140 = 0b10001100;
	const byte mask141 = 0b10001101;
	const byte mask142 = 0b10001110;
	const byte mask143 = 0b10001111;
	const byte mask144 = 0b10010000;
	const byte mask145 = 0b10010001;
	const byte mask146 = 0b10010010;
	const byte mask147 = 0b10010011;
	const byte mask148 = 0b10010100;
	const byte mask149 = 0b10010101;
	const byte mask150 = 0b10010110;
	const byte mask151 = 0b10010111;
	const byte mask152 = 0b10011000;
	const byte mask153 = 0b10011001;
	const byte mask154 = 0b10011010;
	const byte mask155 = 0b10011011;
	const byte mask156 = 0b10011100;
	const byte mask157 = 0b10011101;
	const byte mask158 = 0b10011110;
	const byte mask159 = 0b10011111;
	const byte mask160 = 0b10100000;
	const byte mask161 = 0b10100001;
	const byte mask162 = 0b10100010;
	const byte mask163 = 0b10100011;
	const byte mask164 = 0b10100100;
	const byte mask165 = 0b10100101;
	const byte mask166 = 0b10100110;
	const byte mask167 = 0b10100111;
	const byte mask168 = 0b10101000;
	const byte mask169 = 0b10101001;
	const byte mask170 = 0b10101010;
	const byte mask171 = 0b10101011;
	const byte mask172 = 0b10101100;
	const byte mask173 = 0b10101101;
	const byte mask174 = 0b10101110;
	const byte mask175 = 0b10101111;
	const byte mask176 = 0b10110000;
	const byte mask177 = 0b10110001;
	const byte mask178 = 0b10110010;
	const byte mask179 = 0b10110011;
	const byte mask180 = 0b10110100;
	const byte mask181 = 0b10110101;
	const byte mask182 = 0b10110110;
	const byte mask183 = 0b10110111;
	const byte mask184 = 0b10111000;
	const byte mask185 = 0b10111001;
	const byte mask186 = 0b10111010;
	const byte mask187 = 0b10111011;
	const byte mask188 = 0b10111100;
	const byte mask189 = 0b10111101;
	const byte mask190 = 0b10111110;
	const byte mask191 = 0b10111111;
	const byte mask192 = 0b11000000;
	const byte mask193 = 0b11000001;
	const byte mask194 = 0b11000010;
	const byte mask195 = 0b11000011;
	const byte mask196 = 0b11000100;
	const byte mask197 = 0b11000101;
	const byte mask198 = 0b11000110;
	const byte mask199 = 0b11000111;
	const byte mask200 = 0b11001000;
	const byte mask201 = 0b11001001;
	const byte mask202 = 0b11001010;
	const byte mask203 = 0b11001011;
	const byte mask204 = 0b11001100;
	const byte mask205 = 0b11001101;
	const byte mask206 = 0b11001110;
	const byte mask207 = 0b11001111;
	const byte mask208 = 0b11010000;
	const byte mask209 = 0b11010001;
	const byte mask210 = 0b11010010;
	const byte mask211 = 0b11010011;
	const byte mask212 = 0b11010100;
	const byte mask213 = 0b11010101;
	const byte mask214 = 0b11010110;
	const byte mask215 = 0b11010111;
	const byte mask216 = 0b11011000;
	const byte mask217 = 0b11011001;
	const byte mask218 = 0b11011010;
	const byte mask219 = 0b11011011;
	const byte mask220 = 0b11011100;
	const byte mask221 = 0b11011101;
	const byte mask222 = 0b11011110;
	const byte mask223 = 0b11011111;
	const byte mask224 = 0b11100000;
	const byte mask225 = 0b11100001;
	const byte mask226 = 0b11100010;
	const byte mask227 = 0b11100011;
	const byte mask228 = 0b11100100;
	const byte mask229 = 0b11100101;
	const byte mask230 = 0b11100110;
	const byte mask231 = 0b11100111;
	const byte mask232 = 0b11101000;
	const byte mask233 = 0b11101001;
	const byte mask234 = 0b11101010;
	const byte mask235 = 0b11101011;
	const byte mask236 = 0b11101100;
	const byte mask237 = 0b11101101;
	const byte mask238 = 0b11101110;
	const byte mask239 = 0b11101111;
	const byte mask240 = 0b11110000;
	const byte mask241 = 0b11110001;
	const byte mask242 = 0b11110010;
	const byte mask243 = 0b11110011;
	const byte mask244 = 0b11110100;
	const byte mask245 = 0b11110101;
	const byte mask246 = 0b11110110;
	const byte mask247 = 0b11110111;
	const byte mask248 = 0b11111000;
	const byte mask249 = 0b11111001;
	const byte mask250 = 0b11111010;
	const byte mask251 = 0b11111011;
	const byte mask252 = 0b11111100;
	const byte mask253 = 0b11111101;
	const byte mask254 = 0b11111110;
	const byte mask255 = 0b11111111;

	for( int i = 0; i < 256; ++i )
	{
		switch( i )
		{
			case 0:  
				const byte mask = 0b00000000;
				{
					break;
				}

			case 1:	   
			{
				const byte mask = 0b00000001;
				break;
			}
			case 2:	   const byte mask = 0b00000010;
			{
				break;
			}
			case 3:	   const byte mask = 0b00000011;
			{
				break;
			}
			case 4:	   const byte mask = 0b00000100;
			{
				break;
			}
			case 5:	   const byte mask = 0b00000101;
			{
				break;
			}
			case 6:	   const byte mask = 0b00000110;
			{
				break;
			}
			case 7:	   const byte mask = 0b00000111;
			case 8:	   const byte mask = 0b00001000;
			case 9:	   const byte mask = 0b00001001;
			case 10:   const byte mask = 0b00001010;
			case 11:   const byte mask = 0b00001011;
			case 12:   const byte mask = 0b00001100;
			case 13:   const byte mask = 0b00001101;
			case 14:   const byte mask = 0b00001110;
			case 15:   const byte mask = 0b00001111;
			case 16:   const byte mask = 0b00010000;
			case 17:   const byte mask = 0b00010001;
			case 18:   const byte mask = 0b00010010;
			case 19:   const byte mask = 0b00010011;
			case 20:   const byte mask = 0b00010100;
			case 21:   const byte mask = 0b00010101;
			case 22:   const byte mask = 0b00010110;
			case 23:   const byte mask = 0b00010111;
			case 24:   const byte mask = 0b00011000;
			case 25:   const byte mask = 0b00011001;
			case 26:   const byte mask = 0b00011010;
			case 27:   const byte mask = 0b00011011;
			case 28:   const byte mask = 0b00011100;
			case 29:   const byte mask = 0b00011101;
			case 30:   const byte mask = 0b00011110;
			case 31:   const byte mask = 0b00011111;
			case 32:   const byte mask = 0b00100000;
			case 33:   const byte mask = 0b00100001;
			case 34:   const byte mask = 0b00100010;
			case 35:   const byte mask = 0b00100011;
			case 36:   const byte mask = 0b00100100;
			case 37:   const byte mask = 0b00100101;
			case 38:   const byte mask = 0b00100110;
			case 39:   const byte mask = 0b00100111;
			case 40:   const byte mask = 0b00101000;
			case 41:   const byte mask = 0b00101001;
			case 42:   const byte mask = 0b00101010;
			case 43:   const byte mask = 0b00101011;
			case 44:   const byte mask = 0b00101100;
			case 45:   const byte mask = 0b00101101;
			case 46:   const byte mask = 0b00101110;
			case 47:   const byte mask = 0b00101111;
			case 48:   const byte mask = 0b00110000;
			case 49:   const byte mask = 0b00110001;
			case 50:   const byte mask = 0b00110010;
			case 51:   const byte mask = 0b00110011;
			case 52:   const byte mask = 0b00110100;
			case 53:   const byte mask = 0b00110101;
			case 54:   const byte mask = 0b00110110;
			case 55:   const byte mask = 0b00110111;
			case 56:   const byte mask = 0b00111000;
			case 57:   const byte mask = 0b00111001;
			case 58:   const byte mask = 0b00111010;
			case 59:   const byte mask = 0b00111011;
			case 60:   const byte mask = 0b00111100;
			case 61:   const byte mask = 0b00111101;
			case 62:   const byte mask = 0b00111110;
			case 63:   const byte mask = 0b00111111;
			case 64:   const byte mask = 0b01000000;
			case 65:   const byte mask = 0b01000001;
			case 66:   const byte mask = 0b01000010;
			case 67:   const byte mask = 0b01000011;
			case 68:   const byte mask = 0b01000100;
			case 69:   const byte mask = 0b01000101;
			case 70:   const byte mask = 0b01000110;
			case 71:   const byte mask = 0b01000111;
			case 72:   const byte mask = 0b01001000;
			case 73:   const byte mask = 0b01001001;
			case 74:   const byte mask = 0b01001010;
			case 75:   const byte mask = 0b01001011;
			case 76:   const byte mask = 0b01001100;
			case 77:   const byte mask = 0b01001101;
			case 78:   const byte mask = 0b01001110;
			case 79:   const byte mask = 0b01001111;
			case 80:   const byte mask = 0b01010000;
			case 81:   const byte mask = 0b01010001;
			case 82:   const byte mask = 0b01010010;
			case 83:   const byte mask = 0b01010011;
			case 84:   const byte mask = 0b01010100;
			case 85:   const byte mask = 0b01010101;
			case 86:   const byte mask = 0b01010110;
			case 87:   const byte mask = 0b01010111;
			case 88:   const byte mask = 0b01011000;
			case 89:   const byte mask = 0b01011001;
			case 90:   const byte mask = 0b01011010;
			case 91:   const byte mask = 0b01011011;
			case 92:   const byte mask = 0b01011100;
			case 93:   const byte mask = 0b01011101;
			case 94:   const byte mask = 0b01011110;
			case 95:   const byte mask = 0b01011111;
			case 96:   const byte mask = 0b01100000;
			case 97:   const byte mask = 0b01100001;
			case 98:   const byte mask = 0b01100010;
			case 99:   const byte mask = 0b01100011;
			case 100:  const byte mask = 0b01100100;
			case 101:  const byte mask = 0b01100101;
			case 102:  const byte mask = 0b01100110;
			case 103:  const byte mask = 0b01100111;
			case 104:  const byte mask = 0b01101000;
			case 105:  const byte mask = 0b01101001;
			case 106:  const byte mask = 0b01101010;
			case 107:  const byte mask = 0b01101011;
			case 108:  const byte mask = 0b01101100;
			case 109:  const byte mask = 0b01101101;
			case 110:  const byte mask = 0b01101110;
			case 111:  const byte mask = 0b01101111;
			case 112:  const byte mask = 0b01110000;
			case 113:  const byte mask = 0b01110001;
			case 114:  const byte mask = 0b01110010;
			case 115:  const byte mask = 0b01110011;
			case 116:  const byte mask = 0b01110100;
			case 117:  const byte mask = 0b01110101;
			case 118:  const byte mask = 0b01110110;
			case 119:  const byte mask = 0b01110111;
			case 120:  const byte mask = 0b01111000;
			case 121:  const byte mask = 0b01111001;
			case 122:  const byte mask = 0b01111010;
			case 123:  const byte mask = 0b01111011;
			case 124:  const byte mask = 0b01111100;
			case 125:  const byte mask = 0b01111101;
			case 126:  const byte mask = 0b01111110;
			case 127:  const byte mask = 0b01111111;
			case 128:  const byte mask = 0b10000000;
			case 129:  const byte mask = 0b10000001;
			case 130:  const byte mask = 0b10000010;
			case 131:  const byte mask = 0b10000011;
			case 132:  const byte mask = 0b10000100;
			case 133:  const byte mask = 0b10000101;
			case 134:  const byte mask = 0b10000110;
			case 135:  const byte mask = 0b10000111;
			case 136:  const byte mask = 0b10001000;
			case 137:  const byte mask = 0b10001001;
			case 138:  const byte mask = 0b10001010;
			case 139:  const byte mask = 0b10001011;
			case 140:  const byte mask = 0b10001100;
			case 141:  const byte mask = 0b10001101;
			case 142:  const byte mask = 0b10001110;
			case 143:  const byte mask = 0b10001111;
			case 144:  const byte mask = 0b10010000;
			case 145:  const byte mask = 0b10010001;
			case 146:  const byte mask = 0b10010010;
			case 147:  const byte mask = 0b10010011;
			case 148:  const byte mask = 0b10010100;
			case 149:  const byte mask = 0b10010101;
			case 150:  const byte mask = 0b10010110;
			case 151:  const byte mask = 0b10010111;
			case 152:  const byte mask = 0b10011000;
			case 153:  const byte mask = 0b10011001;
			case 154:  const byte mask = 0b10011010;
			case 155:  const byte mask = 0b10011011;
			case 156:  const byte mask = 0b10011100;
			case 157:  const byte mask = 0b10011101;
			case 158:  const byte mask = 0b10011110;
			case 159:  const byte mask = 0b10011111;
			case 160:  const byte mask = 0b10100000;
			case 161:  const byte mask = 0b10100001;
			case 162:  const byte mask = 0b10100010;
			case 163:  const byte mask = 0b10100011;
			case 164:  const byte mask = 0b10100100;
			case 165:  const byte mask = 0b10100101;
			case 166:  const byte mask = 0b10100110;
			case 167:  const byte mask = 0b10100111;
			case 168:  const byte mask = 0b10101000;
			case 169:  const byte mask = 0b10101001;
			case 170:  const byte mask = 0b10101010;
			case 171:  const byte mask = 0b10101011;
			case 172:  const byte mask = 0b10101100;
			case 173:  const byte mask = 0b10101101;
			case 174:  const byte mask = 0b10101110;
			case 175:  const byte mask = 0b10101111;
			case 176:  const byte mask = 0b10110000;
			case 177:  const byte mask = 0b10110001;
			case 178:  const byte mask = 0b10110010;
			case 179:  const byte mask = 0b10110011;
			case 180:  const byte mask = 0b10110100;
			case 181:  const byte mask = 0b10110101;
			case 182:  const byte mask = 0b10110110;
			case 183:  const byte mask = 0b10110111;
			case 184:  const byte mask = 0b10111000;
			case 185:  const byte mask = 0b10111001;
			case 186:  const byte mask = 0b10111010;
			case 187:  const byte mask = 0b10111011;
			case 188:  const byte mask = 0b10111100;
			case 189:  const byte mask = 0b10111101;
			case 190:  const byte mask = 0b10111110;
			case 191:  const byte mask = 0b10111111;
			case 192:  const byte mask = 0b11000000;
			case 193:  const byte mask = 0b11000001;
			case 194:  const byte mask = 0b11000010;
			case 195:  const byte mask = 0b11000011;
			case 196:  const byte mask = 0b11000100;
			case 197:  const byte mask = 0b11000101;
			case 198:  const byte mask = 0b11000110;
			case 199:  const byte mask = 0b11000111;
			case 200:  const byte mask = 0b11001000;
			case 201:  const byte mask = 0b11001001;
			case 202:  const byte mask = 0b11001010;
			case 203:  const byte mask = 0b11001011;
			case 204:  const byte mask = 0b11001100;
			case 205:  const byte mask = 0b11001101;
			case 206:  const byte mask = 0b11001110;
			case 207:  const byte mask = 0b11001111;
			case 208:  const byte mask = 0b11010000;
			case 209:  const byte mask = 0b11010001;
			case 210:  const byte mask = 0b11010010;
			case 211:  const byte mask = 0b11010011;
			case 212:  const byte mask = 0b11010100;
			case 213:  const byte mask = 0b11010101;
			case 214:  const byte mask = 0b11010110;
			case 215:  const byte mask = 0b11010111;
			case 216:  const byte mask = 0b11011000;
			case 217:  const byte mask = 0b11011001;
			case 218:  const byte mask = 0b11011010;
			case 219:  const byte mask = 0b11011011;
			case 220:  const byte mask = 0b11011100;
			case 221:  const byte mask = 0b11011101;
			case 222:  const byte mask = 0b11011110;
			case 223:  const byte mask = 0b11011111;
			case 224:  const byte mask = 0b11100000;
			case 225:  const byte mask = 0b11100001;
			case 226:  const byte mask = 0b11100010;
			case 227:  const byte mask = 0b11100011;
			case 228:  const byte mask = 0b11100100;
			case 229:  const byte mask = 0b11100101;
			case 230:  const byte mask = 0b11100110;
			case 231:  const byte mask = 0b11100111;
			case 232:  const byte mask = 0b11101000;
			case 233:  const byte mask = 0b11101001;
			case 234:  const byte mask = 0b11101010;
			case 235:  const byte mask = 0b11101011;
			case 236:  const byte mask = 0b11101100;
			case 237:  const byte mask = 0b11101101;
			case 238:  const byte mask = 0b11101110;
			case 239:  const byte mask = 0b11101111;
			case 240:  const byte mask = 0b11110000;
			case 241:  const byte mask = 0b11110001;
			case 242:  const byte mask = 0b11110010;
			case 243:  const byte mask = 0b11110011;
			case 244:  const byte mask = 0b11110100;
			case 245:  const byte mask = 0b11110101;
			case 246:  const byte mask = 0b11110110;
			case 247:  const byte mask = 0b11110111;
			case 248:  const byte mask = 0b11111000;
			case 249:  const byte mask = 0b11111001;
			case 250:  const byte mask = 0b11111010;
			case 251:  const byte mask = 0b11111011;
			case 252:  const byte mask = 0b11111100;
			case 253:  const byte mask = 0b11111101;
			case 254:  const byte mask = 0b11111110;
			case 255:  const byte mask = 0b11111111;
		}
	}
*/
}

void Game::Go()
{
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::RunThreads( int Tid )
{
	int work_load = screen_h / nThreads;
	int start_load = Tid * work_load;
	int end_load = start_load + work_load;
	std::vector<float> obj_intersects, shadow_intersects;
	obj_intersects.reserve( obj_list.size() );

	while( !thread_exit )
	{
		std::unique_lock<std::mutex> lck( mtx );
		while( !ready )
			worker.wait( lck );

		for( int y = start_load; y < end_load; ++y )
		{
			y_amount = ( (float)y + 0.5f ) * rec_sh;

			for( int x = 0; x < screen_w; ++x )
			{
				float x_left = ( (float)x + 0.5f ) * rec_sw;
				x_amount = ( x_left * aspect ) - pix_offset_precalc;

				obj_intersects.clear();

				int index = RenderImage( x_amount, y_amount, obj_intersects );

				if( index < 0 )
					continue;

				const float intersection_dist = obj_intersects[ index ];				
				Vec3 intersection_pos = cam.position + ( cam.direction * intersection_dist );

				if( x == 0 && y == screen_h / 2 )
				{
					int a = 0;
				}
				Color intersection_color = GetColorAt( intersection_pos, cam.direction,
					obj_list, index, pt_light, shadow_intersects, ambient );

				gfx.PutPixel( x, y, intersection_color );
			}
		}

		CheckIn();
		worker.wait( lck );
	}

	CheckIn();
}

int Game::RenderImage( const float XOff, const float YOff, std::vector<float> &Intersects )
{
	Ray ray;

	ray.origin = cam.position;
	ray.direction = Normalize(
		cam.direction +
		( cam.right * ( XOff - 0.5f ) ) +
		( cam.down * ( YOff - 0.5f ) ) );

	for( int i = 0; i < obj_list.size(); ++i )
	{
		float intersect_dist = obj_list[ i ]->FindIntersection( ray );
		Intersects.push_back( intersect_dist );
	}
		
	return FindClosestObject( Intersects );
}

int Game::FindClosestObject( const std::vector<float>& Intersects )
{
	int min_index;
	size_t intersect_count = Intersects.size();
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

			return min_index;
		}
		else
		{
			return -1;
		}
	}
}

void Game::CheckIn()
{
	int wait_count = ++num_waiting;
	if( wait_count == nThreads )
	{
		boss.notify_one();
		num_waiting = 0;
	}
}

Color Game::GetColorAt( const Vec3 &Point_of_Intersection, const Vec3 &Direction_of_Intersection,
	const std::vector<Object*>& ObjectList, const uint32_t Index, const PointLight &Pt_Light, 
	std::vector<float> &ShadowIntersectionDistance, const float AmbientValue )
{
	Vec3 light_direction = Normalize( Pt_Light.position - Point_of_Intersection );
	Vec3 obj_normal = ObjectList[ Index ]->GetNormalAt( Point_of_Intersection );
	Color obj_color = ObjectList[ Index ]->color;

	uint32_t amb_value = ( AmbientValue * 255.0f );
	Color amb = MakeColor( amb_value, amb_value, amb_value );
	Color result_color = obj_color * amb;

	float cosine = DotProduct( obj_normal, light_direction );

	if( cosine > 0.0f )
	{
		bool shadowed = false;

		float light_intensity = Length( light_direction );

		ShadowIntersectionDistance.clear();
		Ray s_ray( Point_of_Intersection, light_direction );

		for( uint32_t i = 0; i < ObjectList.size() && shadowed == false; ++i )
		{
			ShadowIntersectionDistance.push_back( ObjectList[ i ]->FindIntersection( s_ray ) );
		}

		for( uint32_t i = 0; i < ShadowIntersectionDistance.size(); ++i )
		{
			float dist = ShadowIntersectionDistance[ i ];
			if( dist < 0 ) continue;

			if( ShadowIntersectionDistance[ i ] <= light_intensity )
			{
				shadowed = true;
				break;
			}
		}

		if( !shadowed )
		{
			result_color = result_color + (obj_color * Pt_Light.color * (cosine * 255.0f));
			
			/*Vec3 reflection_dir = Normalize(Reflect( Direction_of_Intersection, obj_normal ));
			
			float specular = DotProduct( reflection_dir, light_direction );
			if( specular > 0.0f )
			{
				specular = pow( specular, 10 );
				result_color = result_color + Pt_Light.color * ( 0.3f * specular );
			}*/

		}
	}
	return result_color;
}

void Game::ComposeFrame()
{
	t.StartWatch();

	/*for( int y = 0; y < screen_h; ++y )
	{
		y_amount = ( (float)y + 0.5f ) * rec_sh;

		for( int x = 0; x < screen_w; ++x )
		{
			float x_left = ( (float)x + 0.5f ) * rec_sw;
			x_amount = ( x_left * aspect ) - pix_offset_precalc;

			Ray ray( cam.position, Vec3() );
			ray.direction = Normalize(
				cam.direction +
				( cam.right * ( x_amount - 0.5f ) ) +
				( cam.down * ( y_amount - 0.5f ) ) );
						
			std::vector<float> intersects;
			for( int i = 0; i < obj_list.size(); ++i )
			{
				float intersect_dist = obj_list[ i ]->FindIntersection( ray );
				intersects.push_back( intersect_dist );
			}

			int index = FindClosestObject( intersects );
			if( index < 0 )
				continue;


			gfx.PutPixel( x, y, obj_list[ index ]->color );
		}
	}*/

	std::unique_lock<std::mutex> lck( mtx );
	ready = TRUE;
	worker.notify_all();
	boss.wait(lck);

	t.StopWatch();
	float tm = t.GetTimeMilli();

	std::wostringstream title;
	
	title << 1000.0f / tm << L" fps.\n";
	SetWindowText( hWnd, title.str().c_str() );
}