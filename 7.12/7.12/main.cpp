#include<iostream>
#include<cassert>
using namespace std;

class Datea
{
public:
	Datea()//默认构造
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
	Datea(const Datea &d1)//拷贝构造
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
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
	// 自定义类型
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
		assert(_pData);//断言宏
		_size = 0;
		_capacity = capacity;
	}
	~SeqList()
	{
		if (_pData)
		{
			free(_pData); // 释放堆上的空间
			_pData = NULL; // 将指针置为空
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
	int* p = (int*)&a;//把const int*强转成int*
	*p = 96;//修改指针指向内存单元的值
	cout << a << endl;//输出了6,为什么不是96呢？
	system("pause");
	return 0;
}

//原因是编译器进行了常量优化。
//我们可以添加volatile关键字让编译器不要优化a常量。

int main3() 
{
	const int volatile a = 3;
	int* p = (int*)&a;
	*p = 96;
	cout << a << endl;//输出了96，修改成功
	system("pause");
	return 0;
}

//输入运算符重载
istream &operator>>(istream &in, date &a)
{
	in >>a._day>>a._month>>a._year;
	return in;
}

/*输入输出运算符重载的第一个参数为输入输出流对象的引用
  第二个参数为需要输出类对象的引用
*/

//输出运算符重载
ostream &operator<<(ostream& out, const date&a)
{
	out << "输出内容1" << "输出内容2...";
	return out;
}
/* 为什么输入输出运算符重载要写成友元函数？
因为按照运算符重载的写法，输出运算符重载可以写成 ostream& operator<<(ostream& out, const Date&a)
其第一个参数不是类的对象，所以一旦设为类的成员函数，第一个参数一般是由this指针指向的类对象。
因不符合上述要求，又想该类可以调用此函数，所以将其设为友元函数
*/



//1、内置类型的操作符不能被重载
//2、不能为内置类型定义其他的操作符
//3、操作符重载不能改变操作符的优先级
//4、操作数个数不能改变


