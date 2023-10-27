#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstring>

#include "my_exception.h"

using std::exception;
using std::invalid_argument;
using std::cout;
using std::cerr;
using std::endl;

int parse(const char* s) {
	int r = 0;
	int p = 1;
	int len = strlen(s);
	if (len == 0)
		throw invalid_argument("parse empty string");
	for(int i=len-1; i>=0;i--){
		char c = s[i];
		if ( c == '+' && i == 0) continue;
		if ( c == '-' && i == 0) {
			r = -r;
			continue;
		}
		if (c >= '0' && c <= '9') {
			r += (c-'0')*p;
			p *= 10;
		}
		else
			throw invalid_argument("parse invalid symbol");
	}
	return r;
}

void test(const char* s1, const char* s2) {
	
	try
	{
		int n1 = parse(s1);
		int n2 = parse(s2);
		
		if (n1 < 0 || n1 > 100) throw my_exception("out of range [0, 100]", n1);
		
		if (n2 == 0) throw "divide by zero";
		int n = n1 / n2;
		
		cout << "Result: " << n << endl;
	}
	catch(const my_exception& ex)
	{
		cerr << ex.what() << " Invalid data: " << ex.getInvalidData() << endl;
	}
	catch(const invalid_argument& ex) {
		cerr << "Not a number" << endl;
		throw; // throw ex;
	}

	
	cout << "continue test" << endl;
}


int main(int argc, char** argv) {
	
	try
	{
		test("123", "0");
	}
	catch(const char* s) {
		cerr << s << endl;
	}
	catch(const exception& ex) {
		cerr << ex.what() << endl;
	}	
	catch(...) {
		cerr << "Error" << endl;
	}	
	
	cout << "continue main" << endl;
	
	return 0;
}