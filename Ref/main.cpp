#include <iostream>

using namespace std;

struct Pixel {
	int x;
	int y;
	int color;
	int size;
};

void sw_int(int* pa, int* pb) {
	int c = *pa;
	*pa = *pb;
	*pb = c;
}

inline void swap_int(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}
double max(double a, double b) {
	return (a > b) ? a : b;
}

void draw_pixel(const Pixel& p)
{

	// p.x++;
	std::cout << "Pixel (" << p.x << ", " << p.y <<") " 
		<< "Color: " <<p.color << " Size " <<p.size <<endl;
}
double e = 3.5;
int main(int argc, char** argv) {
	
	cout << max(10, 15) << endl;
	cout << max(2.5, 1.5) << endl;
	
	{
		int e = 8;
		cout << "local e: " << e <<endl;
		cout << "global e: " << ::e <<endl;
	}
	
	{
		int e = 8;
		cout << "local e: " << e <<endl;
		cout << "global e: " << ::e <<endl;
	}
	
	Pixel p;
	p.x = 10;
	p.y = 20;
	p.color = 0xFF0000;
	p.size = 2;
	
	draw_pixel(p);
	
	
	int a = 10;
	int b = 15;
	cout << "a : " << a << " b : " << b << endl;
	sw_int(&a, &b);
	cout << "a : " << a << " b : " << b << endl;
	swap_int(a, b);
	cout << "a : " << a << " b : " << b << endl;
	
	
	
	int k = 10;
	
	int& rk = k;
	rk++;
	
	cout << k << endl;
	
	int* pk = &k;
	int*& pk2 = pk;
	
	(*pk)++;
	
	cout << k << endl;
	
	
	return 0;
}
