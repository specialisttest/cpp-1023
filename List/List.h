#ifndef LIST_H
#define LIST_H

#include <string>
#include <stdexcept>

template<class T>
class List
{
	private:
		template<class T1>
		class Node
		{
			private:
				T1* value;
				Node<T1>* next;
			public:
				Node(T1* _value)
				: value(_value), next(nullptr) {}
				
				T1*  get() const
				{ return this->value; }
				
				virtual ~Node() {
					delete value;
				}
			
			friend class List<T1>;	
				
		};
		
	private:
		Node<T>* first;
		mutable Node<T>* pointer;
		Node<T>* last;
	public:
		List() : first(nullptr), last(nullptr), pointer(nullptr) {}
			
		void add(T* v)
		{
			Node<T>* newNode = new Node<T>(v);
			if (first == nullptr) // empty list
				first = last = newNode;
			else
			{
				last->next = newNode;
				last = newNode;
			}
		}
		
		void start() const
		{
			pointer = nullptr;
		}
		
		T* next() const
		{
			pointer = (pointer == nullptr) ? first : pointer->next;
			return (pointer == nullptr) ? nullptr : pointer->get();
		}
		
		void remove(const T& r) 
		{
			Node<T>* p = first;
			Node<T>* prev = nullptr;
			while(p)
			{
				if ( *(p->get()) == r )
				{ // r for remove
					if (p == first && p == last)
						first = last = nullptr;
					else
					{
						if (p == first)
							first = p->next;
						if (prev != nullptr)
							prev->next = p->next;
					}
					delete p;
					return;
				}
				prev = p;
				p = p->next;
			}
			
			throw std::invalid_argument("Object for remove not found");
		}
		
		void clear()
		{
			Node<T>* p = first;
			while(p)
			{
				Node<T>* pNext = p->next;
				delete p;
				p = pNext;
			}
			
			first = last = pointer = 0;
		}
		
		virtual ~List()
		{
			clear();
		}
		
};

#endif
