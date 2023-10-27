#ifndef _POINT_H_
#define _POINT_H_
#include <iostream>

#include "Shape.h"
#include "Coords.h"
#include "MoveableCoords.h"


using std::cout;
using std::endl;

class Point : public Shape, public MoveableCoords, protected Coords
{
//protected:
//	int x, y;
public:
	Point(int _x = 0, int _y = 0, char* _color = DEFAULT_COLOR) 
		: Shape(_color), Coords(_x, _y)
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
	
	~Point()
	{
		cout << "~Point()" << endl;
	}
	
	
};

#endif