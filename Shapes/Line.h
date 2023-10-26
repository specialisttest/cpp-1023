#ifndef _LINE_H_
#define _LINE_H_

#include <iostream>
#include "Shape.h"

using std::cout;
using std::endl;

class Line : public Shape
{
private:
	int _x1, _y1, _x2, _y2;
public:
	Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, const char* color = DEFAULT_COLOR)
		: Shape(color), _x1(x1), _y1(y1), _x2(x2), _y2(y2)
		{}
		
	int x1() const { return _x1;}
	int y1() const { return _y1;}
	
	Line* x1(int x) { _x1 = x; return this;}
	Line* y1(int y) { _y1 = y; return this;}
	
	int x2() const { return _x2;}
	int y2() const { return _y2;}
	
	Line* x2(int x) { _x2 = x; return this;}
	Line* y2(int y) { _y2 = y; return this;}
	
	void draw() const override 
	{
		cout << "Line. From (" << x1() << ", " << y1() << 
				") to (" << x2() << ", " << y2() << ") " 
				<< color << endl;
	}
	
	void moveBy(int dx, int dy)
	{
		_x1 += dx;
		_y1 += dy;
		_x2 += dx;
		_y2 += dy;
	}
	
	void scale (double factor)
	{
		_x2 = (_x2 - _x1)*factor + _x1;
		_y2 = (_y2 - _y1)*factor + _y1;
	}
	
	
	
};



#endif