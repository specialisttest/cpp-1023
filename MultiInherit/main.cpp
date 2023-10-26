#include <iostream>

using std::cout;
using std::endl;

class A {
	public:
		int x;
		A(int _x = 0) : x(_x) { cout << "A(int)" << endl; }
		
		virtual int getX() { return x; }
		//virtual ~A() { cout << "~A()"<<endl; }
		virtual ~A() = default;
};


class B : virtual public A {
	protected:	int z;
	public:
		int x;
		B(int _x = 0, int _z = 0) : x(_x), z(_z) { cout << "B(int, int)" << endl; }
		int getX() { return x; }
		~B() { cout << "~B()"<<endl; }
};

class C : virtual public A
{
	protected:  int z;
	public:
		C(int _x =0, int _z = 0) : A(_x), z(_z) { cout << "C(int, int)" << endl; }
		~C() { cout << "~C()"<<endl; }

};

class D: virtual public B, virtual public C {
	
	public:
		D(int _x = 0, int _z = 0): B(_x-1, _z - 1), C(_x+1, _z + 1) { cout << "D(int)" << endl; }
		getZ1() { return B::z; }
		getZ2() { return C::z; }
		~D() { cout << "~D()"<<endl; }

	
};


int main(int argc, char** argv) {
	/*B* b = new B(10);
	cout << b->x << endl;	// B::x
	cout << b->B::x << endl;// B::x
	cout << b->A::x << endl;// A::x
	A* ab = b;
	cout << ab->x << endl;	// A::x
	
	cout << b->getX() << endl;	// B::x
	cout << b->B::getX() << endl;// B::x
	cout << b->A::getX() << endl;// A::x
	cout << ab->getX() << endl;	// B::x if getX virtual, else A::x
	*/
	D* d = new D(5);
	cout << d->B::x << endl;
	cout << d->C::x << endl;
	//cout << d->x << endl;
	
	B* bd = d;
	cout << bd->x << endl; 	  // B::x
	cout << bd->A::x << endl; // A::x
	
	C* cd = d;
	cd->x++; // same as cd->A::x and cd->C::x
	cout << cd->x << endl; 	  // C::x ( == A::x)
	cout << cd->A::x << endl; // A::x
	
	//A* ad = static_cast<C*>(d);
	
	A* ad = d;
	cout << cd->x << endl; 	  // A::x
	
	cout << d->getZ1() << endl; // B::z
	cout << d->getZ2() << endl; // C::z
	
	delete ad;
	
	return 0;
}