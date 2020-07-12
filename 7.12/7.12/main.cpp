#include<iostream>
#include<cassert>
using namespace std;

class Datea
{
public:
	Datea()//Ĭ�Ϲ���
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Datea(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Datea(const Datea &d1)//��������
	{
		_year = d1._year;
		_month = d1._month;
		_day = d1._day;
	}
	bool operator==(const Datea& a)
	{
		return this->_year == a._year
			&& _month == a._month
		    && _day == a._day;
	}
	bool operator>(const Datea& a)
	{
		if (_year > a._year)
			return true;
		else if (_year == a._year && _month > a._month)
			return true;
		else if (_year == a._year && _month == a._month &&_day > a._day)
			return true;
		else
			return false;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main5()
{
	Datea a;
	Datea b(1998,9,27);
	a == b;
	return 0;
}










class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class date
{
public:
	// ��������(��������)
	int _year;
	int _month;
	int _day;
	// �Զ�������
	Time _t;
public:
	date()
	{
		cout << "Data()" << endl;
	}
};
int main1()
{
	date d;
	cout << d._year << d._month << d._day << endl;
	system("pause");
	return 0;
}
typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);//���Ժ�
		_size = 0;
		_capacity = capacity;
	}
	~SeqList()
	{
		if (_pData)
		{
			free(_pData); // �ͷŶ��ϵĿռ�
			_pData = NULL; // ��ָ����Ϊ��
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};


int main2() 
{
	const int a = 6;
	int* p = (int*)&a;//��const int*ǿת��int*
	*p = 96;//�޸�ָ��ָ���ڴ浥Ԫ��ֵ
	cout << a << endl;//�����6,Ϊʲô����96�أ�
	system("pause");
	return 0;
}

//ԭ���Ǳ����������˳����Ż���
//���ǿ������volatile�ؼ����ñ�������Ҫ�Ż�a������

int main3() 
{
	const int volatile a = 3;
	int* p = (int*)&a;
	*p = 96;
	cout << a << endl;//�����96���޸ĳɹ�
	system("pause");
	return 0;
}

//�������������
istream &operator>>(istream &in, date &a)
{
	in >>a._day>>a._month>>a._year;
	return in;
}

/*���������������صĵ�һ������Ϊ������������������
  �ڶ�������Ϊ��Ҫ�������������
*/

//������������
ostream &operator<<(ostream& out, const date&a)
{
	out << "�������1" << "�������2...";
	return out;
}
/* Ϊʲô����������������Ҫд����Ԫ������
��Ϊ������������ص�д���������������ؿ���д�� ostream& operator<<(ostream& out, const Date&a)
���һ������������Ķ�������һ����Ϊ��ĳ�Ա��������һ������һ������thisָ��ָ��������
�򲻷�������Ҫ�����������Ե��ô˺��������Խ�����Ϊ��Ԫ����
*/



//1���������͵Ĳ��������ܱ�����
//2������Ϊ�������Ͷ��������Ĳ�����
//3�����������ز��ܸı�����������ȼ�
//4���������������ܸı�


