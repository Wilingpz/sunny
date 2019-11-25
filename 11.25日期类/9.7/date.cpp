//���һ�������࣬�������¹��ܣ�
//1��ֻ��ͨ�����������ճ�ʼ��
//2�����Լ���һ������n�������������ں���n��֮�������
//(һ����30���������)


//���ʵ��
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



int getLeapNum(int sy, int ey)//��������ݣ����������֮���ж���������

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



bool Date::operator <(const Date & d) const//����d��һ��������
	//const����thisָ��Date const * this const ָ���ܱ��ı䣬Ҳ������
	//ͨ��ָ�����ı�ֵ

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



bool Date::operator ==(const Date & d) const//����ʲô��˼��

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
Date Date::operator ++()//������󣬸�������++������մ��ڸ��µ�����������
//��ȥ������������++������´���12�����¼�12������++
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
Date Date::operator ++(int)//��һ��Date���͵���ʱ�������洢++ǰ��ֵ���ڽ���
//����++����������++ǰ��ֵ
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
Date Date::operator --()//�ȸ�day������dayС��1��month�Լ����õ����µ�����
//��day��������µ�����������С��1�����µ���12�����Լ�
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

