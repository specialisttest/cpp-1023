#ifndef _POINT_H_
#define _POINT_H_

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
	
	//Point() : Point(0, 0) {}
	
	Point(int x = 0, int y = 0)
		: _x(x), _y(y)
	{}
	
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