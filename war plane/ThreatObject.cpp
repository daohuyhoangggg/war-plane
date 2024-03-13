
#include "thuvien.h"
#include "ThreatObject.h"

ThreatObject::ThreatObject()
{
	rect_.x = SCREEN_WIDTH;
	rect_.y = SCREEN_HEIGHT;
	rect_.w = WIDTH_THREAT;
	rect_.h = HEIGHT_THREAT;
	
	x_val_ = 0;
	y_val_ = 0;
}
ThreatObject::~ThreatObject()
{
	
}

void ThreatObject::HandleMove(const int & x_border, const int& y_border)
{

}