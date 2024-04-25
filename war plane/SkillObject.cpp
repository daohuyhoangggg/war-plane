
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
	int frequency = rand() % 10 + 1;			// xac xuat xuat hien

	if(frequency <= 8)
	{
		p_object->LoadImg(g_name_skill1_obj);
		p_object->set_type(SkillObject::STAR);
		p_skill_list.push_back(p_object);
	}

	if(frequency >= 9)
	{
		p_object->LoadImg(g_name_skill2_obj);
		p_object->set_type(SkillObject::SHIELD);
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

void SkillObject::Reset(SkillObject* p_skills)
{
	for(int s = 0; s < SKILLS; s++) 
	{
		SkillObject* p_skill = (p_skills + s);
		if(p_skill) 
		{
			rect_.x = SCREEN_WIDTH;

			int rand_y = rand() % MAX_HEIGHT_OF_THREAT + 50;
			if(rand_y > SCREEN_HEIGHT - UNDER_LIMIT_SKILL) {
				rand_y = SCREEN_HEIGHT * 0.3;
			}

			p_skill->SetRect(SCREEN_WIDTH + s * 400, rand_y);
		}
	}
}