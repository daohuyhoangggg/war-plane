
#include "MainObject.h"


MainObject::MainObject()		//construtor
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	x_val_ = 0;
	y_val_ = 0;
	velocity_y = 0;
}

MainObject::~MainObject()
{
	if(p_object_ != NULL)SDL_FreeSurface(p_object_);
}

void MainObject::Flap()
{
	velocity_y = -SPEEDFLY;
}
void MainObject::HandleMove() 
{
	velocity_y += acceleration;
	rect_.y += velocity_y;

	if(velocity_y > 8) velocity_y = 8; // giới hạn tốc độ nhân vật

	if(rect_.y < 0)
	{
		rect_.y = 0;
		velocity_y = 0;
	}

    if (rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT - 45) 
	{
        rect_.y = SCREEN_HEIGHT - 45 - HEIGHT_MAIN_OBJECT;
        velocity_y = 0;
    }
}
