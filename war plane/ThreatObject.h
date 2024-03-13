#ifndef THREAT_OBJECT_H_
#define THREAT_OBJECT_H

#include "thuvien.h"
#include "BaseObject.h"

#define WIDTH_THREAT 80
#define HEIGHT_THREAT 33 


const int UNDER_LIMIT_THREAT = 200;	
const int THREATS = 3;

class ThreatObject : public BaseObject
{
public:

	ThreatObject();
	~ThreatObject();

	void HandleMove(const int& x_border, const int& y_border);
	void set_x_val(const int& val) {x_val_ = val;}
	void set_y_val(const int& val) {y_val_ = val;}
	int get_x_val() const {return x_val_;}
	int get_y_val() const {return y_val_;}

private:
	int x_val_;
	int y_val_;



};
#endif