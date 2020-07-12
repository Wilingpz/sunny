#include<iostream>
using namespace std;

//实现一个日期类

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			//是闰年，二月29天
		{
			return 29;
		}
		return monthDays[month];//是几月就返回该月的天数
	}
	Date(int year, int month, int day)
	{
		if (year > 0 && (month >= 1 && month <= 12) && (day >= 1 && day <= GetMonthDay(year, month)))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
		}
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void print()
	{
		cout << _year << '-' << _month << '-' << _day << endl;
	}

	Date& operator=(const Date&d)//返回值可以做左值的，以引用方式返回
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	Date operator+(int days)//日期加天数,返回值是参数外的另一个类对象
	{
		Date ret(*this);
		ret._day += days;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month += 1;
			if (ret._month == 13)
			{
				ret._month = 1;;
				ret._year++;
			}
		}
		return ret;//临时变量出了作用域就不存在了，所以不用引用做返回值
	}
	Date& operator+=(int days)//日期加天数，返回值是第一个参数
	{
		_day += days;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;//除了函数，这个结果还存在，可以用引用做返回值
	}

	Date operator-(int days)//日期减天数
	{
		Date ret(*this);
		ret._day -= days;
		while (ret._day < 1)
		{
			ret._month -= 1;
			if (ret._month == 0)
			{
				ret._month = 12;
				ret._year--;
			}
			ret._day += GetMonthDay(ret._year, ret._month);
		}
		return ret;
	}
	Date& operator-=(int days)
	{
		_day -= days;
		while (_day <1)
		{
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	int operator-(const Date& d)//日期减日期(考虑到结果的正负)
	{
		//借位相减比较难，每个月的天数以及平闰年的二月天数也不一样
		//所以采用小的日期加上一个天数，得到大的日期
		//而加上的日期就是两个日期之间相差的时间
		int flag = 1;
		Date max(*this);
		Date min = d;//拷贝构造
		//Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int n = 0;
		while (min != max)
		{
			++min;
			++n;//记录一共加了几天
		}
		return flag*n;
	}
	Date& operator++()//前置
	{
		*this += 1;
		return *this;

	}
	Date operator++(int)//后置
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}
	Date& operator--()
	{
		//--d1,前置
		*this -= 1;
		return *this;

	}
	Date operator--(int)
	{
		//d1--，后置
		Date tmp(*this);
		*this -= 1;
		return tmp;//返回--之前的值
	}

	bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month &&_day > d._day)
			return true;
		else
			return false;
	}
	bool operator>=(const Date& d)const
	{
		/*if (_year > d._year)
		return true;
		else if (_year == d._year && _month > d._month)
		return true;
		else if (_year == d._year && _month == d._month &&_day >= d._day)
		return true;
		else
		return false;*/
		return *this > d || *this == d;
	}
	bool operator<(const Date& d)const
		//第二个const ，常成员函数可以理解为是一个“只读”函数，
		//它既不能更改数据成员的值，也不能调用那些能引起数据成员值变化的成员函数
		//只能调用const成员函数。
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month &&_day < d._day)
			return true;
		else
			return false;
	}
	bool operator<=(const Date& d)const
	{
		/*if (_year < d._year)
		return true;
		else if (_year == d._year && _month < d._month)
		return true;
		else if (_year == d._year && _month == d._month &&_day <= d._day)
		return true;
		else
		return false;*/
		return *this < d || *this == d;

	}
	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)const
	{
		return _year != d._year
			|| _month != d._month
			|| _day != d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date a(2020, 7, 12);
	a.print();
	Date b = a + 173;
	b.print();
	int  c = b - a;
	cout << c << endl;
	system("pause");

	return 0;
}