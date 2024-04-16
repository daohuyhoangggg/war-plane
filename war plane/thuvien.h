#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<windows.h>
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include <SDL_mixer.h>
#include<vector>
#include<string>
#include<fstream>

static SDL_Surface* gScreen = NULL;
static SDL_Surface* gBkground = NULL;
static SDL_Surface* gMenu		= NULL;
static SDL_Event gEven;

static Mix_Chunk* g_sound_bullet;
static Mix_Chunk* g_sound_exp[2];
static Mix_Chunk* g_sound_skill[2];

//Screen
const int SCREEN_WIDTH			= 1200;
const int SCREEN_HEIGHT			= 675;
const int SCREEN_BPP			= 32;
const int SCREEN_SPEED			= 2;

// Main object
const int  X_STAR_MAIN			= 150;
const int  Y_STAR_MAIN			= 100;
const int MAX_HEIGHT_OF_MAIN	= SCREEN_HEIGHT - 45;
const int  acceleration			= 1;
const int  SPEEDFLY				= 3;
const int MAX_VELOCITY_Y		= 8;	
const int SPEED_BULLET_MAIN		= 10;

// THREAT OBJECT
const int THREATS				= 2;
const int UNDER_LIMIT_THREAT	= 150;			// giới hạn dưới của mối đe dọa 
const int MAX_HEIGHT_OF_THREAT	= 600;			// độ cao giới hạn 
const int SPEED_THREAT1			= 4;
const int SPEED_THREAT2			=10;
const int SPEED_BULLET_THREAT	= 8;


//EXPLOSION THREAT
const int EXPLOSION_WIDTH		= 165;
const int EXPLOSION_HEIGHT		= 165;
const int NUMBER_OF_FRAMES		= 4;	


// SKILL OBJECT
const int  WIDTH_SKILL			=   50;
const int  HEIGHT_SKILL			=  49;
const int SKILLS				= 3;
const int MAX_HEIGHT_OF_SKILL	= 600;
const int UNDER_LIMIT_SKILL		= 150;
const int TIME_SKILL			= 10;

//GOLD MEDAL
static SDL_Surface* gMedal      = NULL;
const int RECT_X_MEDAL			= 1000;
const int RECT_Y_MEDAL			= 8;
const int MEDAL_WIDTH			= 25;
const int MEDAL_HEIGHT			= 28;

//TEXT OBJECT
const int RECT_X_TEXT = RECT_X_MEDAL + MEDAL_WIDTH + 13;
const int RECT_Y_TEXT = RECT_Y_MEDAL + 10;


static char g_name_back_ground[]		= {"img/background_game.jpg"};
static char g_img_menu[]				= {"img/WAR PLANE.png"};

static char g_name_main_obj[]			= {"img/plane_object.png"};
static char g_name_bullet_main_obj[]	= {"img/bullet_main.png"};


static char g_name_threat1_obj[]			= {"img/threat1.png"};
static char g_name_threat2_obj[]			= {"img/threat2.png"};

static char g_name_bullet_threat_obj[]	= {"img/bullet_threat.png"};

static char g_name_exp_obj[]			= {"img/exp.png"};

static char g_name_skill1_obj[]			= {"img/sao.png"};
static char g_name_skill2_obj[]			= {"img/cuong hoa.png"};
static char g_name_medal[]				= {"img/gold.png"};



static char g_name_sound_bullet_main[]		= {"mix/gun.wav"};
static char g_name_sound_exp_threat_obj[]	= {"mix/Explosion+1.wav"};
static char g_name_sound_exp_main_obj[]		= {"mix/Explosion+9.wav"};
static char g_name_sound_exp_skill1[]		= {"mix/hieu_ung_skill.wav"};
static char g_name_sound_exp_skill2[]		= {"mix/sound_skill2.wav"};

namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);				// tải ảnh 
	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);    // vẽ ảnh src lên des(màn hinh) tại tọa độ(x,y)
	void ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x ,int y);
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);		// xử lý va chạm
	int	 ShowMenu(SDL_Surface* des, TTF_Font* font);
	bool CheckForcusWithRect(const int& x, const int& y, const SDL_Rect& rect);
	void CleanUp();					// Giải phóng tài nguyên
}


#endif