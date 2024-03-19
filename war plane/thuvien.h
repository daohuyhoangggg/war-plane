#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<windows.h>
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include<vector>


const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 675;
const int SCREEN_BPP = 32;
const int SCREEN_SPEED = 2;

static SDL_Surface* gScreen = NULL;
static SDL_Surface* gBkground = NULL;
static SDL_Event gEven;

namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);				// tải ảnh 
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);    // vẽ ảnh src lên des(màn hinh) tại tọa độ(x,y)
	void CleanUp();					// Giải phóng tài nguyên
}

#endif