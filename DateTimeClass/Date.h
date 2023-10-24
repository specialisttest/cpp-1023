#ifndef _DATE_H_
#define _DATE_H_

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
    
    friend bool IsGreater(const Date& d1, const Date& d2);
};

typedef Date* PDate;

bool IsGreater(const Date& d1, const Date& d2);


#endif
