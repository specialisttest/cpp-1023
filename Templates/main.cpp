#include <iostream>

#include "ReadonlyStorage.h"

using std::cout;
using std::endl;

/*int max(int x, int y)
{
	return (x > y) ? x : y;
}

double max(double x, double y)
{
	return (x > y) ? x : y;
}*/

// macro function from C - only for expression
//#define max(x,y) (((x) > (y)) ? (x) : (y))

template<typename T>
T max(T x, T y)
{
	return (x > y) ? x : y;
}

template<typename T>
void my_swap(T& a, T& b){
	T c = a;
	a = b;
	b = c;
}

int main(int argc, char** argv) {
	cout << "max(1,5) : " << max(1,5) << endl;
	cout << "max(1.2,2.1) : " << max(1.2,2.1) << endl;
	cout << "max(1.2,2.1) : " << max<double>(1,2.1) << endl;
	
	{
		int x = 5, y = 7;
		cout << "x = " << x << " y = " << y <<endl;
		my_swap(x,y);
		cout << "x = " << x << " y = " << y <<endl;
	}
	{
		double x = 5.5, y = 7.7;
		cout << "x = " << x << " y = " << y <<endl;
		my_swap(x,y);
		cout << "x = " << x << " y = " << y <<endl;
	}
	{
		ReadonlyStorage r0; 
		
		cout << typeid(r0.getData()).name() << endl;
		
		ReadonlyStorage r1(5);
		cout << r1.getData() << endl;
		
		ReadonlyStorage<int> r2 (7);
		ReadonlyStorage<int> r3 = r1 + r2;
		
		cout << r3.getData() << endl;
		
		ReadonlyStorage<double, 10> r4(2.5);
		cout << r4.getData() << endl;
		cout << r4.getMultypliedData() << endl;
		ReadonlyStorage<double, 10> r5(5.2);
		ReadonlyStorage<double, 10> r6 = r4 + r5;
		
		cout << r6.getData() << endl;
		
		RSD r7(2.7);
		
		cout << r7.getData() << endl;
		
		cout << typeid(r1).name() << endl;
		cout << typeid(r6).name() << endl;
		
		MyClass m1, m2;
		ReadonlyStorage<MyClass> c1(m1);
		ReadonlyStorage<MyClass> c2(m2);
		ReadonlyStorage<MyClass> c3 = c1 + c2;
		
		
	}
	
	
}



