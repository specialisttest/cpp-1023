#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

using std::cout;
using std::endl;

class Point;
double distance(const Point&, const Point&);

class Point
{
private:
	int _x, _y;
	
protected:

public:
	/*inline*/ int getX() const { return _x; }
	void setX(int x) { _x = x > 0 ? x : 0; }
	int getY() const { return _y; }
	void setY(int y) { _y = y; }
	
	void print() const;
	
	//default
	Point() : Point(0, 0) // _x(0), _y(0)
	{
		cout << "ctor Point()" << endl;
	}
	
	// conversion ctor
	// Point(int k) : _x(k), _y(k)
	explicit Point(int k) : Point(k,k) //_x(k), _y(k)
	{
		cout << "ctor Point(int)" << endl;
	}
	
	// copy ctor
	Point(const Point& p) : Point(p._x, p._y)//_x(p._x), _y(p._y)
	{
		cout << "ctor Point(const Point&)" << endl;
	}
	
	// copy operator
	Point& operator =(const Point& p);

	
	Point(int x, int y)	: _x(x), _y(y)
	{
		cout << "ctor Point(int,int)" << endl;
	}
	
	~Point() {
		cout << "~Point()" << endl;
	}
	
	
	
	double distance(const Point& p) const {
		return ::distance(*this, p);
	}
	double distance() const {
		Point p(0,0);
		return ::distance(*this, p);
	}
	
	friend double distance(const Point&, const Point&);
	friend class Trasform;
};

class Trasform
{
	public:
		void transit(Point& p, int dx, int dy)
		{
			//p.setX(p.getX()+dx);
			p._x += dx;
			p._y += dy;
		}
		
};


#endif