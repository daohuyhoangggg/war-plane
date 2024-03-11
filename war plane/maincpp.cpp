#include "thuvien.h"




bool init();  // Thiet lap cua so man hinh

int  main(int arc, char* argv[])
{
	int back_x = 0;
	//bool is_run = true;
	bool is_quit = false;

	if(!init())return -1;

	gBkground = SDLCommonFunc::LoadImage("img/background_game.jpg");
	if(gBkground == NULL)return -1;

	
	
	while(!is_quit)			// cap nhap man hình
		{
		while(SDL_PollEvent(&gEven))
		{
			if(gEven.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
		
		}

	
		SDLCommonFunc::ApplySurface(gBkground, gScreen, 0, 0);
		

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

