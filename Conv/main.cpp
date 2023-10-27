#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;
using std::type_info;
using std::boolalpha;

int main(int argc, char** argv) {
	double x = 2.5;
	
	cout << typeid(x).name() << endl;
	cout << typeid(int*).name() << endl;
	
	const type_info& t = typeid(int*);
	
	int n = x;
	int n1 = 6;;
	cout << boolalpha;
	cout << (typeid(n) == typeid(x)) << endl;
	cout << (typeid(n) == typeid(n1)) << endl;
	
	cout << x << endl; 
	cout << n << endl;
	
	void *p = &n;
	
	int *pz = 0;
	
	unsigned long long y = reinterpret_cast<long long>(pz);
	
	
	int* px = (int*)p; // c
	
	int* px2 = static_cast<int*>(p); // c++
	
	(*px)++;
	cout << n << endl;
	
	const int* pcn = px2; // &n;
	
	int* pm = const_cast<int*>(pcn);
	
	volatile int* pcm = px2;
	
	int* pq = const_cast<int*>(pcm);
	
	bool a = true;
	bool b = false;
	
	bool c = !(a || c);
	
	cout << c <<endl;
	int m[3] = {1,2,3};
	for(auto &item : m)
		cout << item;
	
	
	
	
	
	return 0;
}
