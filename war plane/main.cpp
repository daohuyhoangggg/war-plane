#include "thuvien.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatObject.h"


bool init();  // Thiet lap cua so man hinh

int  main(int arc, char* argv[])
{

	if(!init())return -1;

	gBkground = SDLCommonFunc::LoadImage("img/background_game.jpg");
	if(gBkground == NULL)return -1;

	// Create MainObject
	MainObject plane_object;
	bool ret = plane_object.LoadImg("img/plane_fly.png");		// load ảnh nhân vật
	plane_object.SetRect(100,100);
	if(ret == NULL) 
	{
		 printf( "Unable to load image %s! SDL Error: %s\n", "img/plane_fly.png", SDL_GetError() );
		return false;
	}
	
	// Create ThreatObject
	ThreatObject* p_threats = new ThreatObject[THREATS];
	for(int t = 0; t < THREATS; t++)
	{}
	bool is_quit = false;
	bool is_mouseButton = false;
	while(!is_quit)			// cap nhap man hình
	{
			
				while(SDL_PollEvent(&gEven))
				{
					if(gEven.type == SDL_QUIT){
						is_quit = true;
						break;
					}
					else if (gEven.type == SDL_MOUSEBUTTONDOWN) {
						if (gEven.button.button == SDL_BUTTON_LEFT) {
							is_mouseButton = true;	
							plane_object.Flap();			// Đặt biến trạng thái là true khi chuột được nhấn
					}
				}		
				else if (gEven.type == SDL_MOUSEBUTTONUP) {
					if (gEven.button.button == SDL_BUTTON_LEFT) {
						is_mouseButton = false;				// Đặt biến trạng thái là false khi chuột được nhả
					}
				}
		}
		if(is_mouseButton){
			plane_object.Flap();
		}	
		
		SDLCommonFunc::ApplySurface(gBkground, gScreen, 0, 0);
		plane_object.Show(gScreen); // tải ảnh nhân vật

		// Make MainObject
		plane_object.HandleMove();
		plane_object.Show(gScreen);

		// Update screen
		if(SDL_Flip(gScreen) == -1)return -1;			// hiển thị
	}


	SDLCommonFunc::CleanUp();
	SDL_Quit();

	return 0;	
}

bool init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)					// khởi tạo các thành phần của SDL
	{
		return false;
	}
	gScreen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT,SCREEN_BPP, SDL_SWSURFACE);						// thiết lập cửa sổ video
	if(gScreen == NULL)
	{
		return false;
	}
	return true;
}

