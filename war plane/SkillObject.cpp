
#include "SkillObject.h"

SkillObject::SkillObject()
{
	rect_.x = SCREEN_WIDTH;
	rect_.y = SCREEN_HEIGHT;
	rect_.w = WIDTH_SKILL;
	rect_.h = HEIGHT_SKILL;
}

SkillObject::~SkillObject()
{
	;
}

void SkillObject::InitSkill(SkillObject* p_object)
{
	int frequency1 = rand() % 10 + 1;			// xác suất xuất hiện của skill

	if(frequency1 <= 5)
	{
		p_object->LoadImg(g_name_skill_obj);
		p_object->set_type(SkillObject::STAR);
		p_skill_list.push_back(p_object);
	}


}

void SkillObject::MakeSkill(SDL_Surface* des, const int& x_limit, const int& y_limit)
{
	for(int i = 0; i < p_skill_list.size(); i++)
	{
		SkillObject* p_skill = p_skill_list.at(i);

		if(p_skill)
		{
			p_skill->Show(des);
		}
	}
}

void SkillObject::HandleMove(const int & x_border, const int& y_border)
{
	rect_.x -= SCREEN_SPEED + 1;
	int rand_y = 0;
	if(rect_.x < 0)
	{
		rect_.x = SCREEN_WIDTH;
		rand_y = rand()% MAX_HEIGHT_OF_SKILL + 10;
		if(rand_y > SCREEN_HEIGHT - UNDER_LIMIT_SKILL)
		{
			rand_y = SCREEN_HEIGHT * 0.3;
		}
		rect_.y = rand_y;
	}	

}

void SkillObject::Reset(const int& x_border)
{
	rect_.x = x_border;
	int rand_y = rand()% MAX_HEIGHT_OF_SKILL + 10;
	if(rand_y > SCREEN_HEIGHT - UNDER_LIMIT_SKILL)
	{
		rand_y = SCREEN_HEIGHT * 0.3;
	}
	rect_.y = rand_y;

}