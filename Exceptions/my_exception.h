#ifndef _MY_EXCEPTION_H_
#define _MY_EXCEPTION_H_

#include <stdexcept>

class my_exception : public std::invalid_argument
{
	private:
		int invalidData;
		
	public:
		my_exception(const char* __arg, int _invalidData)
			: std::invalid_argument(__arg), invalidData(_invalidData) {	}
			
		int getInvalidData() const {return invalidData;}
	
};

#endif