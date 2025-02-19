#ifndef EXPLOSION_OBJECT_H_
#define EXPLOSION_OBJECT_H_

#include "BaseObject.h"
#include "thuvien.h"


class ExplosionObject : public BaseObject
{
public:
	ExplosionObject();
	~ExplosionObject();

	void set_clip();
	void set_frame(const int& fr) {frame_ = fr;}
	void ShowEx(SDL_Surface * des);
private:
	int frame_;
	SDL_Rect clip_[4];
};

#endif