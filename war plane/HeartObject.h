
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
	void SetNumber(const int& num) {number_ = num;}		// số lượng trái tim
	void AddPos(const int& npos);
	void Render(SDL_Surface* des);						// cập nhập vị trí			
	void Init();										//  cập nhập lại 
	void Decrease();
private:
	int number_;
	std::vector <int> pos_list_;
};

#endif
