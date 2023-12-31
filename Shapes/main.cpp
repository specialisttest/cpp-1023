#include <iostream>

#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Line.h"
#include "Scene.h"

int main(int argc, char** argv) {
	/*Point p1(10, 20, "green");
	//p1.draw(); // Point::draw()
	p1.moveBy(2, 3);
	//p1.draw();
	
	Shape& sr1 = p1; // "восходящее" преобразование
	sr1.draw();*/
	
	
	Point* pp1 = new Point(10, 20, "green");
	pp1->setX(11);
	pp1->setY(21);
	//pp1->draw(); // Point::draw()
	
	Shape* s1 = pp1; // "восходящее" преобразование
	//s1->draw(); // Point::draw() если он virtual, Shape::draw() если он не виртуальный
	
	//s1->Shape::draw(); // Shape::draw()
	Circle* pc1 = new Circle(100, 200, 50, "pink");
	pc1->moveBy(15, 16);
	pc1->scale(1.5);
	//pc1->draw();
	
	Line* l1 = new Line;
	//l1->x1(10);
	//l1->y1(20);
	l1->x1(10)->y1(20)
	  ->x2(100)->y2(200);
	  
	Scene* pscene = new Scene;
	pscene->add(pp1);
	pscene->add(pc1);
	pscene->add(l1);
	pscene->draw();
	
	//delete s1;
	
	delete pscene;
	
	
	return 0;
}