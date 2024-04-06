
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
void MainObject::CreateBullet()
{
	BulletObject* p_bullet = new BulletObject();
	p_bullet->SetWidthHeight(WIDTH_BULLET, WIDTH_BULLET);
	p_bullet->LoadImg(g_name_bullet_main_obj);
	p_bullet->set_type(BulletObject::BULLET_MAIN);

	p_bullet->SetRect(this->rect_.x + this->rect_.w - 30 , this->rect_.y + this->rect_.h * 0.8);
	p_bullet->set_is_move(true);
	p_bullet->set_x_val(SPEED_BULLET_MAIN);

	p_bullet_list.push_back(p_bullet);
	
}

void MainObject::MakeBullet(SDL_Surface* des)
{
	for(int i = 0; i < p_bullet_list.size(); i++)
		{
			
			BulletObject* p_bullet = p_bullet_list.at(i);
			if(p_bullet != NULL)
			{
				if(p_bullet->get_is_move())
				{
					p_bullet->HandleMove(SCREEN_WIDTH , SCREEN_HEIGHT);
					p_bullet->Show(des);
				}
				else 
				{
					if(p_bullet != NULL)
					{
						p_bullet_list.erase(p_bullet_list.begin() + i);
						delete p_bullet;
						p_bullet = NULL;
					}
				}
			}
		}
}

void MainObject::HandleMove() 
{
	velocity_y += acceleration;
	rect_.y += velocity_y;

	if(velocity_y > MAX_VELOCITY_Y) velocity_y = MAX_VELOCITY_Y;    // giới hạn tốc độ nhân vật

	if(rect_.y < 0)
	{
		rect_.y = 0;
		velocity_y = 0;
	}

	if (rect_.y + HEIGHT_MAIN_OBJECT >  MAX_HEIGHT_OF_MAIN) 
	{
		rect_.y = MAX_HEIGHT_OF_MAIN - HEIGHT_MAIN_OBJECT;
        velocity_y = 0;
    }
}
