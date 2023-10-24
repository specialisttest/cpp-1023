#include <iostream>
#include <cmath>
#include "Point.h"

void Point::print() const
{
	//const Point* this
	std::cout << '(' << this->getX() << ", " << getY() << ')' << std::endl;
}

double distance(const Point& p1, const Point& p2)
{
	return sqrt( pow(p1._x-p2._x, 2) +  pow(p1.getY()-p2.getY(), 2));
}

Point& Point::operator =(const Point& p)
{
	_x = p._x;
	_y = p._y;
	cout << "operator =(const Point&)" << endl;
	return *this;
}
