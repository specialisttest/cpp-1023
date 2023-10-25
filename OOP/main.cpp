#include <iostream>
#include "Point.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv) {
	
	Point::printTotal();
	
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
	
	// Point p4 = 4; // Point p4(4)
	Point p4(4);
	
	p4.print();
	
	//Point(100, 100);
	Point(100, 100).print();
	
	Point p5 = p4; // copy ctor
	p4.print();
	p5.print();
	
	delete pp3;
	
	p1 = p2; // copy operator
	//p1.operator =(p2);
	
	// p5.~Point(); // special case
	p1.setX(1);
	p1.setY(2);
	p2.setX(20);
	p2.setY(30);
	
	p1.print();
	p2.print();
	//Point p3 = p1.add(p2); // p1 + p2
	//Point p3 = p1 + p2;
	//p1.operator+(p2);
	//p3 = p1 + 5;
	//p3 = 5 + p1;
	Point p3(2,3);
	p3.print();
	p3 += p2; // p3 = p3 + p2;
	
	p3.print();
	p3[0] = 100;
	
	cout << p3[0] << ", " << p3[1] << endl;
	//       p3.getX()        p3.getY()
	
	Point p6(6,7);
	Point p7(6,7);
	p6.print();
	p7.print();
	
	if (p6 == p7)
		cout << "p6 == p7" <<endl;
	else
		cout << "p6 != p7" <<endl;
	
	p1.setX(28);
	p1.setY(29);
		
	cout << p1 << endl;
	
	cout << ++p1 << endl;
	cout << p1 << endl;
	
	cout << p1++ << endl;
	cout << p1 << endl;
	
	cout << "OK" << endl;
	
	/*Point p8;
	cout << "Enter coords (x, y): ";
	cin >> p8;
	
	cout << p8 << endl;*/
	
	//int k =10;
	//int p = ++k; // k == 11 , p == 11 - prefix
	//int p = k++; // k == 11,  p == 10 -suffix (postfix)
	//cout << "k = " << k << ", p = " << p <<endl;
	
	
	
	Point::printTotal();
	
}