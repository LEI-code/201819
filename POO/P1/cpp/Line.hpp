#include <cmath>
#include <stdio.h>

class Line{
	double slope;
	double b;		//if vertical means x, if horizontal means y
	double normalGetY(double x){return this->slope*x+this->b;}
	double normalGetX(double y){return (y - this->b)/this->slope;}
	double verticalGetY(double x){/*this is impossible*/}
	double verticalGetX(double y){return this->b;}
	double horizontalGetY(double x){return this->b;}
	double horizontalGetX(double y){/*this is impossible*/}
	double (Line::*y)(double);
	double (Line::*x)(double);
public:
	Line(double x1, double y1, double x2, double y2){
		double xdif = x2-x1;
		if(!xdif){//vertical
			this->slope = NAN;
			this->b = x1;
			this->x = &Line::verticalGetX;
			this->y = &Line::verticalGetY;
		}else{
			double ydif = y2-y1;
			if(!ydif){//horizontal
				this->slope = 0;
				this->b = y1;
				this->x = &Line::horizontalGetX;
				this->y = &Line::horizontalGetY;
			}else{
				this->slope = ydif/xdif;
				this->b = y1-this->slope*x1;
				this->x = &Line::normalGetX;
				this->y = &Line::normalGetY;
			}
		}
	}
	bool isHorizontal(){return  this->slope == 0;}
	bool isVertical()  {return  this->slope == NAN;}
	double Y(double X) {return (this->(*this->y))(X);}
	double X(double Y) {return (this->(*this->x))(Y);}
};