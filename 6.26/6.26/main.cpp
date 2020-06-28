#include<iostream>
using namespace std;
//指针和引用
int main1()
{
	int a = 10;
	int& ra = a;
	ra = 20;
	int* pa = &a;
	*pa = 20;
	return 0;
}
//c++11的auto
int main2()
{
	int a = 0;
	auto b = a;//编译器在编译时期推导b的类型为int
	int &c = a;
	auto& d = a;

	auto*e = &a;
	auto f = &a;//也是int*

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;
	//typeid函数用于打印变量的类型
	system("pause");
	return 0;
}
//范围for的应用
int main3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		array[i] *= 2;
	}
	//c++11 范围for
	for (auto &e : array)
	{
		e *= 2;
	}
	for (auto &i : array)
	{
		cout << i << endl;
	}
	return 0;
}

void TestFor(int array[])
{
	//for (auto &i : array)//因为array已经不再是数组了，这里已经退化成了指针
	//{
	//	cout << i << endl;
	//}
	cout << *array + 1 << *array + 2 << *array + 3 << endl;//234
}
int main4()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	TestFor(array);
	system("pause");
	return 0;
	
}
//指针空值

void fun(int n)
{
	cout << "整形" << endl;
}
void fun(int*p)
{
	cout << "整形指针" << endl;
}
int main()
{
	//C
	int *p1 = NULL;
	//C++11中，推荐
	int *p2 = nullptr;
	fun(0);//整型
	fun(NULL);//整型，预处理后 fun(0)
	fun((int*)NULL);
	fun(nullptr);//整型指针  fun((void*)0)

	system("pause");
	return 0;
}
//类与对象
//类里可以定义成员变量和成员函数
class Person
{
public:
	void ShowInfo()
	{
		cout << name << endl;
		cout << age << endl;
	}
private:
	char name[10];//10字节
	int age;//4字节
	int _capacity;//4字节
};
//1、C语言中struct是用来定义结构体的
//2、C++中，兼容C的struct定义结构体的用法。但是同时struct也可以用来定义类
//3、C++中使用class和struct定义类的区别，一个默认访问限定符是public，一个默认访问限定符是public

struct ListNode_C
{
	int _val;
	struct ListNode_c* _next;
	//只有加上struct才是一个类型
	struct ListNode_c* _prev;
};
struct ListNode_CPP
{
	int _val;
	struct ListNode_CPP* _next;
	ListNode_CPP* _prev;//定义类的时候，可以加struct也可以不加struct
	//还可以定义成员函数
	ListNode_CPP* CreatNode(int val);
};
//声明和定义的区别
//声明是一种承诺，承诺要干嘛，但是还没做，定义就是把这个是落地了
int main6()
{
	Person s1;//类实例化出对象，相当于定义出了类的成员变量
	return 0;
}
//计算类对象的大小
int main7()
{
	//Person
	Person	s1;
	cout << sizeof(s1) << endl;//20
	system("pause");
	return 0;
}
class Stack
{
public:
	void Push(int x)
	{

	}
	void Pop();
	bool Empty();
	
	int *_a;//四字节
	int _size;//四字节
	int _capacity;//四字节
};
int main8()
{
	Stack s1;
	cout<<sizeof(s1)<<endl;//12
	system("pause");
	return 0;
}
//对象中只存储成员变量，不存储成员函数，成员函数在公共代码段

//类中有成员变量和成员函数
class A1
{
public:
	void f1();
private:
	int _a;
};
//类中只有成员函数
class A2
{
public:
	void f2(){};
};
//类中什么都没有
class A3
{};

int main()

{
	A1 s1;
	A2 s2;
	A3 s3;
	cout << sizeof(s1) << endl;//4
	cout << sizeof(s2) << endl;//1
	cout << sizeof(s3) << endl;//1
	//没有成员变量或者空类，其大小为1，而不是0。
	//不是为了存储数据，而是为了占位，表示对象存在。
	system("pause");
	return 0;
}
//this指针
class Date
{
public:
	void Display()
	{
		cout << this->_year << "-" <<this-> _month << "-" << this->_day << endl;
		/*cout << _year << "-" << _month << "-" << _day << endl;*/
	}
	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;//可以加上this指针

		/*_year = year;
		_month = month;
		_day = day;*/
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
int main()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d2.SetDate(2018, 7, 1);
	//d1.Display(Date *this);//错的不可以写出来
	d2.Display();
	return 0;
}
//this指针是否可以为空
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main10()
{
	Date* p = NULL;
	p->PrintA();//程序崩溃 //p->PrintA(p)
	p->Show();//正常运行
	//A a;
	//a.PrintA(); //p->PrintA(&a)
}