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
	bool ret = plane_object.LoadImg("img/plane_object.png");		// load ảnh nhân vật
	plane_object.SetRect(100,100);
	if(ret == NULL) 
	{
		 printf( "Unable to load image %s! SDL Error: %s\n", "img/plane_object.png", SDL_GetError() );
		return 0;
	}
	
	// Create ThreatObject
	ThreatObject* p_threats = new ThreatObject[THREATS];
	for(int t = 0; t < THREATS; t++)
	{
		ThreatObject* p_threat = (p_threats + t);
		if(p_threat)
		{
			ret = p_threat->LoadImg("img/threat.png");
			if(ret == NULL)
			{
				printf( "Unable to load image %s! SDL Error: %s\n", "img/threat.png", SDL_GetError() );
				return 0;
			}

			int rand_y = rand()% 600 + 1;
			if(rand_y > SCREEN_HEIGHT - 250)
			{
				rand_y = SCREEN_HEIGHT * 0.3;
			}

			p_threat->SetRect(SCREEN_WIDTH + t*400, rand_y);		// lam cho cac threat xuat hien khac thoi diem
			p_threat->set_x_val(5);

			// nap dan cho doi tuong threat
			BulletObject* p_bullet = new BulletObject();
			p_threat->InitBullet(p_bullet);

		}
	
	}

	
	bool is_quit = false;
	bool is_mouseButton = false;
	bool is_play = false;
	int speed_screen = 0;

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
							is_play = true;
							plane_object.Flap();
							plane_object.CreateBullet();		// Đặt biến trạng thái là true khi chuột được nhấn
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
		

		// apply background && xử lý di chuyển màn hình
		speed_screen -= SCREEN_SPEED;
		SDLCommonFunc::ApplySurface(gBkground, gScreen, speed_screen, 0);
		SDLCommonFunc::ApplySurface(gBkground, gScreen, speed_screen + SCREEN_WIDTH, 0);
		if (speed_screen <= -SCREEN_WIDTH) speed_screen = 0;

		// Make MainObject
		if(is_play)
		{
			plane_object.HandleMove();
		}
		plane_object.Show(gScreen);
		plane_object.MakeBullet(gScreen); // xử lý đạn cho đối tượng chính

		// Make ThreatObject
		for(int tt = 0; tt < THREATS; tt++)
		{
			ThreatObject* p_threat = (p_threats + tt);
			if(p_threat)
			{
				p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_threat->Show(gScreen);
				if(p_threat->GetRect().x > plane_object.GetRect().x)
				{
					p_threat->MakeBullet(gScreen, SCREEN_WIDTH, SCREEN_HEIGHT);

					// xử lý va chạm giữa main và bullet_threat 
					std::vector<BulletObject*>bulletT_list = p_threat->GetBulletList();
					for(int  bt = 0; bt < bulletT_list.size(); bt++)
					{
						bool is_col = SDLCommonFunc::CheckCollision(plane_object.GetRect(), bulletT_list.at(bt)->GetRect());
						if(is_col){

							if(MessageBox(NULL, L"GAME OVER!", L"Info", MB_OK) == IDOK)
							{
								SDLCommonFunc::CleanUp();
								SDL_Quit();
								return -1;
							}
						}
					} 			
				}
			}
		}

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

