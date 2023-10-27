#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

using std::cerr;
using std::endl;;


template<typename T, int max_size = 100>
class Stack
{
	private:
		T* stack;
		int top;
	public:
		Stack(int size = max_size) : top(0)
		{
			stack = new T[size];
		}
		
		virtual ~Stack() {
			//std::cout << "~Stack()" << endl;
			delete []stack;
		}
		
		void push(const T& x) {
			if (!isFull()) stack[top++] = x;
			else cerr << "stack overflow" << endl;
		}
		
		
		T pop() {
			if (!isEmpty()) return stack[--top];
			else cerr << "stack is empty" << endl;
			return T();
		}
		
		int size() { return top; }
		bool isEmpty() { return size() == 0; }
		bool isFull() { return size() == max_size;}
		
		
};


#endif