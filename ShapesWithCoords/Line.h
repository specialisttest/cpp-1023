#ifndef _LINE_H_
#define _LINE_H_

#include <iostream>
#include "Shape.h"
#include "IScaleable.h"

using std::cout;
using std::endl;

class Line :  public IScaleable /* should be first for VS*/, public Shape
{
protected:
	Coords c1, c2;
public:
	Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, const char* color = DEFAULT_COLOR)
		: Shape(color)
		{
			c1=Coords(x1,y1);
			c2=Coords(x2,y2);
		}
		
	int x1() const { return c1.x;}
	int y1() const { return c1.y;}
	
	Line* x1(int x) { c1.x = x; return this;}
	Line* y1(int y) { c1.y = y; return this;}
	
	int x2() const { return c2.x;}
	int y2() const { return c2.y;}
	
	Line* x2(int x) { c2.x = x; return this;}
	Line* y2(int y) { c2.y = y; return this;}
	
	void draw() const override 
	{
		cout << "Line. From (" << x1() << ", " << y1() << 
				") to (" << x2() << ", " << y2() << ") " 
				<< color << endl;
	}
	
	void moveBy(int dx, int dy)
	{
		c1.moveBy(dx, dy);
		c2.moveBy(dx, dy);
	}
	
	void scale (double factor) override
	{
		x2((x2() - x1())*factor + x1());
		y2((y2() - y1())*factor + y1());
	}
	
	
	
};



#endif