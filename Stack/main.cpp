#include <iostream>
#include <cstring>

#include "Stack.h"

using std::cout;
using std::boolalpha;

bool verifyParntness(const char* s)
{
	int len = strlen(s);
	Stack<char>* st = new Stack<char>(len);
	for(int i=0; i < len; i++){
		char ch = s[i];
		if (ch == '(' || ch == '[')
			st->push(ch);
		if (ch == ')' || ch == ']')
			if (st->isEmpty()) return false;
			else
			{
				char ch2 = st->pop();
				if ( !((ch2 == '(' && ch ==')') || (ch2 == '[' && ch ==']') ))
				return false;
			}
	}
	bool result = st->isEmpty();
	delete st;
	return result;
	
}

int main(int argc, char** argv) {
	Stack<int>* st = new Stack<int>;
	
	cout << "empty: " << boolalpha << st->isEmpty() << endl;
	cout << "full : " << st->isFull() << endl;

	st->push(1);
	st->push(2);
	st->push(3);
	
	cout << "size: " << st->size() << endl;
	cout << "empty: " << boolalpha << st->isEmpty() << endl;
	cout << "full : " << st->isFull() << endl;
	
	
	
	while (!st->isEmpty())
		cout << st->pop() << endl;
		
	cout << "empty: " << boolalpha << st->isEmpty() << endl;
	cout << "full : " << st->isFull() << endl;
	
	delete st;
	
	const char* str = "(  ( [ + ] ) - [ ] * () )";
	
	cout << "For string '" << str << "': "
		<< verifyParntness(str) << endl;
	
	
}