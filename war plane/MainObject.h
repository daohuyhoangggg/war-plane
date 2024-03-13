
#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "BaseObject.h"
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

private:
	int x_val_;
	int y_val_;
	int velocity_y;
};
#endif