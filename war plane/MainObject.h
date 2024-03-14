
#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "BaseObject.h"
#include "AmoObject.h"
#include "thuvien.h"


#define WIDTH_MAIN_OBJECT 80
#define HEIGHT_MAIN_OBJECT 45

const int  acceleration = 1;
const int  SPEEDFLY = 3;

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	void Flap();			
	void HandleMove();		// Xu ly di chuyen

	void CreateAmo();
	void MakeAmo(SDL_Surface* des);

	void SetAmoList(std::vector<AmoObject*> amo_list) {p_amo_list = amo_list;}			
	std::vector<AmoObject*> GetAmoList() const {return p_amo_list;}

private:
	int x_val_;
	int y_val_;
	int velocity_y;
	std::vector<AmoObject*> p_amo_list;
};
#endif