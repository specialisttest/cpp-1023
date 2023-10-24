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