#include <iostream>

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
	
	
}



