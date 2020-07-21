#include<iostream>
using namespace std;


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
	int GetDayofYear()
	{
		int sum = 0;
		if (_month==1)
		{
			return _day;
		}
		else
		{
			for (int i = 1; i < _month; i++)
			{
				sum += GetMonthDay(_year, i);
			}
			sum += _day;
		}
		return sum;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		Date a(year, month, day);
		cout<<a.GetDayofYear()<<endl;
	}
	system("pause");
	return 0;
}