#include "thuvien.h"
#include "figure.h"




bool init();  // Thiet lap cua so man hinh

int  main(int arc, char* argv[])
{

	if(!init())return -1;

	gBkground = SDLCommonFunc::LoadImage("img/background_game.jpg");
	if(gBkground == NULL)return -1;

	FigureObject figure;
	bool ret = figure.LoadImg("img/plane_fly.png");		// load ảnh nhân vật
	figure.SetRect(100,100);
	if(ret == NULL) 
	{
		 printf( "Unable to load image %s! SDL Error: %s\n", "img/plane_fly.png", SDL_GetError() );
		return false;
	}
	
	bool is_quit = false;
	while(!is_quit)			// cap nhap man hình
	{
			
				while(SDL_PollEvent(&gEven))
				{
					if(gEven.type == SDL_QUIT){
						is_quit = true;
						break;
					}
				}
		
		
		SDLCommonFunc::ApplySurface(gBkground, gScreen, 0, 0);
		figure.Show(gScreen); // tải ảnh nhân vật

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

