#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<windows.h>
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include<vector>

// Screen
static SDL_Surface* gScreen = NULL;
static SDL_Surface* gBkground = NULL;
static SDL_Event gEven;

const int SCREEN_WIDTH			= 1200;
const int SCREEN_HEIGHT			= 675;
const int SCREEN_BPP			= 32;
const int SCREEN_SPEED			= 2;

// Main object
const int  X_STAR_MAIN			= 150;
const int  Y_STAR_MAIN			= 15;
const int MAX_HEIGHT_OF_MAIN	= SCREEN_HEIGHT - 45;
const int  acceleration			= 1;
const int  SPEEDFLY				= 3;
const int MAX_VELOCITY_Y		= 8;	
const int SPEED_BULLET_MAIN		= 10;

// THREAT OBJECT
const int THREATS			= 2;
const int UNDER_LIMIT_THREAT	= 200;			// giới hạn dưới của mối đe dọa 
const int MAX_HEIGHT_OF_THREAT	= 600;			// độ cao giới hạn 
const int SPEED_THREAT			= 6;
const int SPEED_BULLET_THREAT	= 8;


//EXPLOSION THREAT
const int EXPLOSION_WIDTH		= 165;
const int EXPLOSION_HEIGHT		= 165;
const int NUMBER_OF_FRAMES		= 4;	



namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);				// tải ảnh 
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);    // vẽ ảnh src lên des(màn hinh) tại tọa độ(x,y)
	void ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x ,int y);
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);		// xử lý va chạm
	void CleanUp();					// Giải phóng tài nguyên
}

#endif