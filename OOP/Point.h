#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class Point;
double distance(const Point&, const Point&);

class Point
{
private:
	int _x, _y;
	static int counterCreated;
	mutable int printCounter; // разрешено менять даже const методам
	
protected:

public:
	const int z;
	
	const static int DEFAULT_SHIFT_Z = 10;
	
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
	
	//Point(const Point& p) = delete;
	//Point& operator =(const Point& p) = delete;
	

	
	Point(int x, int y)	: _x(x), _y(y), z( x + y + DEFAULT_SHIFT_Z), printCounter(0)
	{
		cout << "ctor Point(int,int)" << endl;
		Point::counterCreated++;
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
	
	Point add(const Point& p) const;
	Point operator +(int k) const; // Point + int
	Point& operator +=(const Point& p);
	
	//Point operator +(const Point& p) const;
	//int operator [](int i); // only read
	int& operator [](int i); //lvalue
	
	Point& operator ++(); // prefix ++
	Point operator ++(int); // postfix ++
	
	
	static void printTotal();
	
	friend double distance(const Point&, const Point&);
	friend class Trasform;
};

Point operator +(const Point& p1, const Point& p2);
Point operator +(int, const Point& p2);

bool operator ==(const Point& p1, const Point& p2);

ostream& operator <<(ostream& s, const Point& p);
istream& operator >>(istream& s, Point& p);

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