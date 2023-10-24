#include <cstdlib> // stdlib.h
#include <iostream>

//using namespace std;
using std::cout;
using std::endl;
using std::cin;

/*
// C
void swap(int* pa, int* pb)
{
	int c = *pa;
	*pa = *pb;
	*pb = c;
}
*/

void swap(int& a, int& b)
{
	int	c = a;
	a = b;
	b = c;
}
inline constexpr int max(int a, int b)
{
	//cout << "MAX" << endl;
	return (a > b) ? a : b;
}

void sayHello()
{
	cout << "Привет!" << endl;
}
// C
//void sayHelloWithName(const char* name)
// С++
void sayHello(const char* name, const char endSymbol = '.') 
{
	cout << "Привет, " << name << endSymbol << endl;
}

struct Person
{
	char* name;
	int   age;
};

int main(int argc, char** argv) {
	system("chcp 65001 > nul"); // utf-8
	
	/*sayHello();
	sayHello("Сергей", '!');
	sayHello("Надежда", '.');
	sayHello("Андрей");*/
	
	struct Person p; // C and C++
	Person p1;		 // only C++
	
	char name[32];
	cout << "Введите ваше имя: " ;
	cin >> name;
	sayHello(name, '!');
	
	/*
		блочный комментарий
	
	*/
	// строчоный комментарий
	
	
	
	//std::cout << "Hello ugly world!" << std::endl;
	cout << "Hello ugly world!" << endl;
	cout << "Привет ужасный мир!" << endl;
	
	int a = 5, b =7;
	
	int k;
	k = a+1, b+1;
	
	cout << "k = " << k << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	
	// C pointer
	int* pa = &a;
	(*pa)++; // a++
	int*& pa2 = pa;
	(*pa2)++; // a++
	
	// C++ reference
	int& r = a;
	r++; // a++;
	a = 5; b= 7;
	cout << "a = " << a << endl << "b = " << b << endl;
	
	//swap(&a, &b); // C
	swap(a, b); // C++
	
	cout << "a = " << a << endl << "b = " << b << endl;
	
	/*int x;
	cout << "Введите число: ";
	cin >> x;
	x *= 2; // x = x * 2;
	cout << "Увеличенное в два раза число: " << x << endl;*/
	
	int* pi = new int(5);
	cout << *pi << endl;
	delete pi;
	
	pi = NULL;
	delete pi; // разрешено для пустого указателя
	
	
	
	int* m = new int[5];
	for(int i=0; i < 5; i++)
		m[i] = 0;
		
	cout << endl;
	
	delete []m;
	
	
	k = max(7, 5); // k = 7;
	cout << "k = " << k << endl;
	
	int nums[5] = {10, 20, 30, 40, 50};
	
	//for(int i=0; i < 5; i++)
		//cout << nums[i] << " ";
		//nums[i]++;
	
	for(auto& n : nums)
		n++;
	
	cout << endl;
	
	// foreach
	for(auto n : nums) 
		cout << n << " ";
		
		
	for(const auto n : nums) {
		cout << n << " ";
		// n++; // error
	}
		
		
	const int q = 10;
	cout << "const q = " << q << endl;
	// q++; // error 
	
	int numbers[5] = {11,12,13,14,15};
	int summa = 0;
	//for(int i=0; i <5; i++)
	//	summa += numbers[i];
	for(auto n : numbers)
		summa += n;
		
	cout << "Сумма: " << summa << endl;
	
	int x = 5;
	//double y = (double)x / 2; // C and C++ (not recommended)
	//double y = double(x) / 2; // C++ only  (not recommended)
	// C++ only
	double y = static_cast<int>(x) / 2;
	// const_cast<>() // отмена const и volatile
	//reinterpret_cast<>()
	//dynamic_cast<>()
	
	// NULL 
	
	cout << typeid(p).name() << endl;
	
	cout << y << endl;
	
	
	
	
	
	return 0;
}