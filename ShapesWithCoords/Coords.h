#ifndef _COORDS_H_
#define _COORDS_H_

#include <iostream>

using std::ostream;

class Coords
{
public:
	int x, y;
	Coords(int _x = 0, int _y = 0) 
		: x(_x), y(_y) {}
		
	void moveBy(int dx, int dy) {
		x += dx; y+= dy;
	}
};

ostream& operator <<(ostream& s, const Coords& c);

#endif