#include <iostream>
#include "Point.h"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
	int x;
	int* px = &x;
	int& rx = x;
	
	Point p1(10, 20);
	//p1.Point::x = 10;
	//p1.y = 20;
	//p1.setX(-10);
	//p1.setY(20);
	
	Point* pp1 = &p1;
	Point& pr1 = p1;
	
	//pr1.y += 5;
	pr1.setY(pr1.getY()+5);
	
	
	//pp1->x++;     // (*pp1).x++;
	pp1->setX(pp1->getX()+1);
	
	pp1->print(); // (*pp1).print();
	
	Point p2;
	//p2.setX(100);
	//p2.setY(200);
	p2.print();
	
	cout << "Distance between p1 and p2: " << distance(p1, p2) << endl;
	
	const Point* pp3 = new Point(1000, 2000);
	pp3->print();
	cout << "Distance between pp3 and p1: " << pp3->distance(p1) << endl;
	cout << "Distance between pp3 and (0, 0): " << pp3->distance() << endl;
	
	//p1.print();
	
	delete pp3;
	
}