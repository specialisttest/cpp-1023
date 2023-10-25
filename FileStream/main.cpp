#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const char* fname = "test.txt";

int main(int argc, char** argv) {
	
	ifstream f(fname, ios::in);
	
	char name[100];
	while (!f.eof())
	{
		int age;
		f >> name >> age;
		cout << "Name: " << setw(10) << left << name << " Age: " << age << endl;
	}
	f.close();
	
	ofstream w(fname, ios::app);
	w.seekp(0, ios::end);
	w << setw(12) << left << "Konstantin" <<  17 << endl;
	w.close();
	
	
	
	return 0;
}