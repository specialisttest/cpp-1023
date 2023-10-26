#include "Coords.h"

ostream& operator <<(ostream& s, const Coords& c)
{
	s << "(" << c.x << ", " << c.y << ")";
}