//设计一个日期类，包含以下功能：
//1、只能通过传入年月日初始化
//2、可以加上一个数据n，返回体格该日期后推n天之后的日期
//(一个月30天向后推算)


//类的实现
#include "date.h"



static uint getMonthDay(int y, uint m)

{

	if (m > 12 || m == 0)

	{

		return 0;

	}



	if (m == 4 || m == 6 || m == 9 || m == 11)

	{

		return 30;

	}

	else if (m == 2)

	{

		return 28 + (y % 400 == 0 || (y % 4 == 0 && y % 100));

	}

	else

	{

		return 31;

	}

}



int getLeapNum(int sy, int ey)//给两个年份，算这两年份之间有多少年闰年

{

	int tmp = sy % 4;

	if (tmp)

	{

		sy += (4 - tmp);

	}

	return (ey - sy) / 4 + 1;

}



Date Date::operator + (uint delay) const

{

	Date res = *this;

	uint tmp;

#if 0

	int numy = delay / 365;

	int numd = delay % 365;

	int flag = 0;



	if (res.m_month > 2)

	{

		flag = 1;

	}

	int leapnum = getLeapNum(res.m_year + flag, res.m_year + numy);

	while (numd < leapnum)

	{

		numy--;

		leapnum = getLeapNum(res.m_year + flag, res.m_year + numy);

		numd += 365;

	}

	numd -= leapnum;



	res.m_year += numy;

	delay = numd;

#endif



	tmp = getMonthDay(res.m_year, res.m_month);

	while (delay >= tmp)

	{

		delay -= tmp;

		res.m_month++;

		if (res.m_month > 12)

		{

			res.m_month = 1;

			res.m_year++;

		}

		tmp = getMonthDay(res.m_year, res.m_month);

	}



	res.m_day += delay;

	if (res.m_day > tmp)

	{

		res.m_month++;

		if (res.m_month > 12)

		{

			res.m_month = 1;

			res.m_year++;

		}

		res.m_day -= tmp;

	}



	return res;

}



ostream & operator << (ostream & os, Date & d)

{

	os << d.m_year << '-' << d.m_month << '-' << d.m_day;

	return os;

}



bool Date::operator <(const Date & d) const//对于d是一个常引用
	//const修饰this指针Date const * this const 指向不能被改变，也不可以
	//通过指针来改变值

{

	if (m_year < d.m_year)

	{

		return true;

	}



	if (m_year == d.m_year && m_month < d.m_month)

	{

		return true;

	}



	else if (m_year == d.m_year &&

		m_month == d.m_month &&

		m_day < d.m_day)

	{

		return true;

	}

	return false;

}



bool Date::operator >(const Date & d) const

{

	if (m_year > d.m_year)

	{

		return true;

	}



	if (m_year == d.m_year && m_month > d.m_month)

	{

		return true;

	}



	else if (m_year == d.m_year &&

		m_month == d.m_month &&

		m_day > d.m_day)

	{

		return true;

	}

	return false;

}



bool Date::operator <=(const Date & d) const

{

	return !(*this > d);

}



bool Date::operator >=(const Date & d) const

{

	return !(*this < d);

}



bool Date::operator ==(const Date & d) const//这是什么意思？

{

	if (m_year == d.m_year &&

		m_month == d.m_month &&

		m_day == d.m_day)

	{

		return true;

	}

	return false;

}



bool Date::operator !=(const Date & d) const

{

	return !(*this == d);

}
Date Date::operator ++()//传入对象，给它的日++，如果日大于该月的天数，给它
//减去该月天数，月++，如果月大于12，给月减12，给年++
{
	uint tmp;
	tmp = getMonthDay(m_year, m_month);
	m_day++;
	if (++m_day > tmp)
	{
			m_day = m_day - tmp;//m_day = 1;
			++m_month;
		if (m_month > 12)
		{
			m_month = m_month - 12;//m_month = 1;
			++m_year;
		}
	}
	return *this;
}
Date Date::operator ++(int)//给一个Date类型的临时变量，存储++前的值，在进行
//上述++操作，返回++前的值
{
	Date temp(*this);
	uint tmp;
	tmp = getMonthDay(m_year, m_month);
	m_day++;
	if (++m_day > tmp)
	{
		m_day = m_day - tmp;//m_day = 1;
		++m_month;
		if (m_month > 12)
		{
			m_month = m_month - 12;//month = 1;
			++m_year;
		}
	}
	return temp;
}
Date Date::operator --()//先给day减，若day小于1，month自减并得到该月的天数
//令day等于这个月的天数，若月小于1，让月等于12，年自减
{
	uint tmp;
	m_day--;
	if (--m_day < 1)
	{
		--m_month;
		if (m_month < 1)
		{
			m_month = 12;
			--m_year;
		}
		tmp = getMonthDay(m_year, m_month);
		m_day = tmp;
	}
	return *this;
}
Date Date::operator --(int)
{
	Date temp(*this);
	uint tmp;
	m_day--;
	if (--m_day < 1)
	{
		--m_month;
		if (m_month < 1)
		{
			m_month = 12;
			--m_year;
		}
		tmp = getMonthDay(m_year, m_month);
		m_day = tmp;
	}
	return temp;
}

