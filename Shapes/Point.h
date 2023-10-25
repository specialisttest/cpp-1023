#ifndef _POINT_H_
#define _POINT_H_
#include <iostream>

#include "Shape.h"

using std::cout;
using std::endl;

class Point : public Shape
{
protected:
	int x, y;
public:
	Point(int _x = 0, int _y = 0, char* _color = DEFAULT_COLOR) : Shape(_color), x(_x), y(_y)
	{
		cout << "Point(int,int)" <<endl;
	}
	
	
	int getX() const { return x;}
	int getY() const { return y;}
	
	void setX(int _x) { x = _x; }
	void setY(int _y) {  y= _y; }
	
	void draw() const override 
	{
		//this->Shape::draw();	
		cout << "Point. (" << getX() << ", " << getY() << ") " << getColor() << endl;
	}
	
	void moveBy(int dx, int dy)
	{
		x += dx;
		y += dy;
	}
	
	~Point()
	{
		cout << "~Point()" << endl;
	}
	
	
};

#endif