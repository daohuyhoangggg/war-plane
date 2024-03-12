
#include "MainObject.h"


MainObject::MainObject()		//construtor
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	x_val_ = 0;
	y_val_ = 0;
}

MainObject::~MainObject()
{
	if(p_object_ != NULL)SDL_FreeSurface(p_object_);
}

void MainObject::Flap()
{

}
void MainObject::HandleMove() 
{
    
}
