#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

using std::ostream;
using std::istream;

/*
	Перегрузить операторы == << >>  >  <
*/
class Date
{
private:
    int _year;
    int _month;
    int _day;
public:
	Date( int year, int month, int day)
		: _year(year), _month(month), _day(day)
	{}

	Date();
	
	int year() const {return _year;}
	int month() const {return _month;}
	int day() const {return _day;}
	
    void set(int year = 2000, int month = 1, int day = 1);
    void print() const;
    void read();

    int CompareTo(const Date& d) const;
    
    bool Equal(const Date* d) const
	{
		return CompareTo(*d) == 0;
	}
    bool Less(const Date* d)  const
	{
		return CompareTo(*d) < 0;
	}
	bool Greater(const Date* d) const
	{
		return CompareTo(*d) > 0;
	}
	
    bool operator <(const Date& d)  const
	{
		return Less(&d);
	}
	bool operator >(const Date& d) const
	{
		return Greater(&d);
	}
    
    friend bool IsGreater(const Date& d1, const Date& d2);
};

typedef Date* PDate;

bool IsGreater(const Date& d1, const Date& d2);
bool operator ==(const Date& d1, const Date& d2);
ostream& operator <<(ostream& s, const Date& d);
istream& operator >>(istream& s, Date& d);


#endif
