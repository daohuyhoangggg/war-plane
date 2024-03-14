
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
void MainObject::CreateAmo()
{
	AmoObject* p_amo = new AmoObject();
	p_amo->SetWidthHeight(WIDTH_BULLET, WIDTH_BULLET);
	p_amo->LoadImg("img/laser.png");
	p_amo->set_type(AmoObject::LAZER);

	p_amo->SetRect(this->rect_.x + this->rect_.w - 30 , this->rect_.y + this->rect_.h * 0.8);
	p_amo->set_is_move(true);
	p_amo->set_x_val(8);

	p_amo_list.push_back(p_amo);
	
}

void MainObject::MakeAmo(SDL_Surface* des)
{
	for(int i = 0; i < p_amo_list.size(); i++)
		{
			
			AmoObject* p_amo = p_amo_list.at(i);
			if(p_amo != NULL)
			{
				if(p_amo->get_is_move())
				{
					p_amo->HandleMove(SCREEN_WIDTH , SCREEN_HEIGHT);
					p_amo->Show(des);
				}
				else 
				{
					if(p_amo != NULL)
					{
						p_amo_list.erase(p_amo_list.begin() + i);
						delete p_amo;
						p_amo = NULL;
					}
				}
			}
		}
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
