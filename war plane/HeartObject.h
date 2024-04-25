
#ifndef HEART_PLAYER_H_
#define HEART_PLAYER_H_

#include "BaseObject.h"
#include "BaseObject.h"
#include <vector>

class HeartPlayer : public BaseObject
{
public:
	HeartPlayer();
	~HeartPlayer();
	void SetNumber(const int& num) {number_ = num;}		// so luong trai tim
	void AddPos(const int& npos);
	void Render(SDL_Surface* des);						// cap nhap vi tri			
	void Init();										//  cap nhap lai
	void Decrease();
private:
	int number_;
	std::vector <int> pos_list_;
};

#endif
