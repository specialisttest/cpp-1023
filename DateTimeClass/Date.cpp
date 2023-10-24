#include <iostream>
#include <ctime>
#include "Date.h"

Date::Date()
{
	time_t t = time(NULL);
	struct tm now = *localtime(&t);
	_year = now.tm_year + 1900;
	_month = now.tm_mon+1;
	_day = now.tm_mday;
	
}

void Date::set(int _year, int month, int day)
{
    if (_year >= 1 && _year <= 2100)
        this->_year = _year;
    if (month >= 1 && month <=12)
        _month = month;
    if (day >= 1 && day <= 31)
        this->_day = day;
}

using namespace std;

void Date::print() const
{
    cout << _year << '.' << _month << '.' << _day << endl;
}
void Date::read()
{
    cout << "Year (1-2100): ";
    int year;
    cin >> year;
    cout << "Month (1-12): ";
    int month;
    cin >> month;
    cout << "Day (1-31): ";
    int day;
    cin >> day;
    set(year, month, day);
}

int Date::CompareTo(const Date& d) const
{
    if (this->_year == d._year && this->_month == d._month &&
        this->_day == d._day) return 0;
    
    return IsGreater(*this, d) ? 1:-1;
}

bool IsGreater(const Date& d1, const Date& d2) 
{
    if (d1._year > d2._year) return true;
    if (d1._year == d2._year)
    {
        if (d1._month > d2._month) return true;
        if (d1._month == d2._month)
            if (d1._day > d2._day) return true;
    }
    return false;
}

