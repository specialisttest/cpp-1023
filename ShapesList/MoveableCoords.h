#ifndef _MOVEABLE_COORDS_H_
#define _MOVEABLE_COORDS_H_

#include "IMoveable.h"

class MoveableCoords : public IMoveable
{
	public:

		virtual int getX() const = 0;
		virtual int getY() const = 0;
		
		virtual void setX(int _x) = 0;
		virtual void setY(int _y) = 0;

		void moveBy(int dx, int dy) override
		{
			setX(getX() + dx);
			setY(getY() + dy);
		}
		
	
};

#endif