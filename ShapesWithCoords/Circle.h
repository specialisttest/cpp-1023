#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <iostream>
#include "Shape.h"
#include "IScaleable.h"
#include "MoveableCoords.h"

using std::cout;
using std::endl;

class Circle : public Shape, public IScaleable, public MoveableCoords, protected Coords
{
protected:
	int r;

public:
	Circle(int _x = 0, int _y = 0, int _r = 1, const char* _color = DEFAULT_COLOR)
		: Shape(_color), Coords(_x, _y), r(_r)
	{}
	
	int getX() const {return x;}
	int getY() const {return y;}
	int getR() const {return r;}
	
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void setR(int _r) { r = _r; }
	
	void draw() const override
	{
		cout << "Circle. (" << getX() << ", " << getY() <<") "
			<< "Radius: " << getR() << " Color: " << getColor() << endl;
	}
	
	void scale(double factor) override
	{
		r *= factor;
	}
	~Circle()
	{
		cout << "~Circle()" << endl;
	}	
};


#endif