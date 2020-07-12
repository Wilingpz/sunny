#include<iostream>
using namespace std;

//ʵ��һ��������

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			//�����꣬����29��
		{
			return 29;
		}
		return monthDays[month];//�Ǽ��¾ͷ��ظ��µ�����
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
			cout << "�Ƿ�����" << endl;
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

	Date& operator=(const Date&d)//����ֵ��������ֵ�ģ������÷�ʽ����
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	Date operator+(int days)//���ڼ�����,����ֵ�ǲ��������һ�������
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
		return ret;//��ʱ��������������Ͳ������ˣ����Բ�������������ֵ
	}
	Date& operator+=(int days)//���ڼ�����������ֵ�ǵ�һ������
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
		return *this;//���˺����������������ڣ�����������������ֵ
	}

	Date operator-(int days)//���ڼ�����
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
	int operator-(const Date& d)//���ڼ�����(���ǵ����������)
	{
		//��λ����Ƚ��ѣ�ÿ���µ������Լ�ƽ����Ķ�������Ҳ��һ��
		//���Բ���С�����ڼ���һ���������õ��������
		//�����ϵ����ھ�����������֮������ʱ��
		int flag = 1;
		Date max(*this);
		Date min = d;//��������
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
			++n;//��¼һ�����˼���
		}
		return flag*n;
	}
	Date& operator++()//ǰ��
	{
		*this += 1;
		return *this;

	}
	Date operator++(int)//����
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}
	Date& operator--()
	{
		//--d1,ǰ��
		*this -= 1;
		return *this;

	}
	Date operator--(int)
	{
		//d1--������
		Date tmp(*this);
		*this -= 1;
		return tmp;//����--֮ǰ��ֵ
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
		//�ڶ���const ������Ա�����������Ϊ��һ����ֻ����������
		//���Ȳ��ܸ������ݳ�Ա��ֵ��Ҳ���ܵ�����Щ���������ݳ�Աֵ�仯�ĳ�Ա����
		//ֻ�ܵ���const��Ա������
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