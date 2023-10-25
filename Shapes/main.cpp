#include <iostream>

#include "Shape.h"
#include "Point.h"

int main(int argc, char** argv) {
	/*Point p1(10, 20, "green");
	//p1.draw(); // Point::draw()
	p1.moveBy(2, 3);
	//p1.draw();
	
	Shape& sr1 = p1; // "восходящее" преобразование
	sr1.draw();*/
	
	
	Point* pp1 = new Point(10, 20, "green");
	//pp1->draw(); // Point::draw()
	
	Shape* s1 = pp1; // "восходящее" преобразование
	s1->draw(); // Point::draw() если он virtual, Shape::draw() если он не виртуальный
	
	//s1->Shape::draw(); // Shape::draw()
	
	delete s1;
	
	
	return 0;
}