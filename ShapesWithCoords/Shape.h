#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <cstring>

/*
	class Shape
		color
		Shape(..) ~Shape()
		virtual draw()
	class Point : Shape
		x, y, Point(...)
		draw() override
		moveBy(dx,dx)
	class Circle : Shape
		x,y,r, Circle(...)
		draw() override
		scale(double factor)
		moveBy(dx,dx)
	class Line : Shape
		x1,y1,x2,y2,Line(...)
		draw()
		moveBy(dx,dx)
		scale(factor)
	class Scene
		Shape*	objects[100];
		draw()
		add(Shape* s)
		clear()
	
		

*/

using std::cout;
using std::endl;

class Shape
{
	// int z; // private
	
	
private:
	void copyRef(const Shape& s)
	{	
		this->color = strcpy(new char[strlen(s.color)+1], s.color);
	}
	
protected:
	char* color;
	
public:
	constexpr static char* DEFAULT_COLOR = "black";
	
	char* getColor() const { return color; }
	
	Shape(const char* _color = DEFAULT_COLOR)
	{
		color = new char[strlen(_color)+1];
		strcpy(color, _color);
		cout << "Shape(char*)" <<endl;
	}
	
	Shape(const Shape& s)
	{
		copyRef(s);
	}
	Shape& operator = (const Shape& s)
	{
		copyRef(s);
		return *this;
	}
	
	virtual void draw() const = 0;
	/*{
		cout << "Shape. " << this->getColor()  << endl;
	}*/
	
	virtual ~Shape()
	{
		cout << "~Shape()" << endl;
		delete []color;
		color = NULL;
	}
	
};

#endif