
#include"thuvien.h"

SDL_Surface* SDLCommonFunc::LoadImage(std::string file_path)
{
	SDL_Surface* loadImage = NULL;				// lưu trữ hình ảnh từ file
	SDL_Surface* optimizeImage = NULL;			// lưu trữ hình ảnh được tối ưu hóa

	loadImage = IMG_Load(file_path.c_str());

	if(loadImage != NULL)
	{
		optimizeImage = SDL_DisplayFormat(loadImage);			// tối ưu hóa hình ảnh
		SDL_FreeSurface(loadImage);

		if(optimizeImage != NULL)
		{
				// loại bỏ background của cái đối tượng con
				UINT32 color_key = SDL_MapRGB(optimizeImage->format, 0, 0xFF, 0xFF);		
				SDL_SetColorKey(optimizeImage, SDL_SRCCOLORKEY, color_key);

		}
	}
	return optimizeImage;
}

void SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)				// vẽ lên tọa độ cụ thể
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}

void SDLCommonFunc::CleanUp()
{
	SDL_FreeSurface(gScreen);
	SDL_FreeSurface(gBkground);
}