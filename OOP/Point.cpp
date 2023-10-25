#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Point.h"

int Point::counterCreated = 0;

void Point::print() const
{
	//const Point* this
	this->printCounter++;
	std::cout << '(' << this->getX() << ", " << getY() 
		<< ") z: " << this->z 
		<< " print counter: " << this->printCounter << std::endl;
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

void Point::printTotal()
{
	cout << "Total points: " << Point::counterCreated << endl;
}

Point Point::add(const Point& p) const
{
	return Point(this->getX() + p.getX(), this->getY() + p.getY());
}

/*Point Point::operator +(const Point& p) const
{
	return this->add(p);
	//return Point(this->getX() + p.getX(), this->getY() + p.getY());
}*/
Point operator +(const Point& p1, const Point& p2)
{
	return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
}

Point Point::operator +(int k) const
{
	return Point(this->getX() + k, this->getY() + k);
}
Point operator +(int k, const Point& p2)
{
	return p2 + k;
}

Point& Point::operator +=(const Point& p)
{
	this->_x += p._x;
	this->_y += p._y;
	return *this;
}

int& Point::operator [](int i)
{
	switch(i)
	{
		case 0 : return _x;
		case 1 : return _y;
		default:
			throw std::out_of_range("Point coords index out of range [0,1]");
	}
}

bool operator ==(const Point& p1, const Point& p2)
{
	return (p1.getX() == p2.getX()) && (p1.getY() == p2.getY());
}

ostream& operator <<(ostream& s, const Point& p) 
{
	s << p.getX() << ", " << p.getY();
	return s;
}

istream& operator >>(istream& s, Point& p)
{
	int x,y;
	s >> x;
	s >> y;
	p.setX(x);
	p.setY(y);
	return s;
}

// prefix ++
Point& Point::operator++()
{
	this->_x++;
	this->_y++;
	return *this;
}

// postfix ++
Point Point::operator ++(int)
{
	Point pv(*this);
	//this->_x++;
	//this->_y++;
	++(*this);
	return pv;
}







