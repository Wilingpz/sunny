#include<iostream>
using namespace std;
//ָ�������
int main1()
{
	int a = 10;
	int& ra = a;
	ra = 20;
	int* pa = &a;
	*pa = 20;
	return 0;
}
//c++11��auto
int main2()
{
	int a = 0;
	auto b = a;//�������ڱ���ʱ���Ƶ�b������Ϊint
	int &c = a;
	auto& d = a;

	auto*e = &a;
	auto f = &a;//Ҳ��int*

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;
	//typeid�������ڴ�ӡ����������
	system("pause");
	return 0;
}
//��Χfor��Ӧ��
int main3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		array[i] *= 2;
	}
	//c++11 ��Χfor
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
	//for (auto &i : array)//��Ϊarray�Ѿ������������ˣ������Ѿ��˻�����ָ��
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
//ָ���ֵ

void fun(int n)
{
	cout << "����" << endl;
}
void fun(int*p)
{
	cout << "����ָ��" << endl;
}
int main()
{
	//C
	int *p1 = NULL;
	//C++11�У��Ƽ�
	int *p2 = nullptr;
	fun(0);//����
	fun(NULL);//���ͣ�Ԥ����� fun(0)
	fun((int*)NULL);
	fun(nullptr);//����ָ��  fun((void*)0)

	system("pause");
	return 0;
}
//�������
//������Զ����Ա�����ͳ�Ա����
class Person
{
public:
	void ShowInfo()
	{
		cout << name << endl;
		cout << age << endl;
	}
private:
	char name[10];//10�ֽ�
	int age;//4�ֽ�
	int _capacity;//4�ֽ�
};
//1��C������struct����������ṹ���
//2��C++�У�����C��struct����ṹ����÷�������ͬʱstructҲ��������������
//3��C++��ʹ��class��struct�����������һ��Ĭ�Ϸ����޶�����public��һ��Ĭ�Ϸ����޶�����public

struct ListNode_C
{
	int _val;
	struct ListNode_c* _next;
	//ֻ�м���struct����һ������
	struct ListNode_c* _prev;
};
struct ListNode_CPP
{
	int _val;
	struct ListNode_CPP* _next;
	ListNode_CPP* _prev;//�������ʱ�򣬿��Լ�structҲ���Բ���struct
	//�����Զ����Ա����
	ListNode_CPP* CreatNode(int val);
};
//�����Ͷ��������
//������һ�ֳ�ŵ����ŵҪ������ǻ�û����������ǰ�����������
int main6()
{
	Person s1;//��ʵ�����������൱�ڶ��������ĳ�Ա����
	return 0;
}
//���������Ĵ�С
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
	
	int *_a;//���ֽ�
	int _size;//���ֽ�
	int _capacity;//���ֽ�
};
int main8()
{
	Stack s1;
	cout<<sizeof(s1)<<endl;//12
	system("pause");
	return 0;
}
//������ֻ�洢��Ա���������洢��Ա��������Ա�����ڹ��������

//�����г�Ա�����ͳ�Ա����
class A1
{
public:
	void f1();
private:
	int _a;
};
//����ֻ�г�Ա����
class A2
{
public:
	void f2(){};
};
//����ʲô��û��
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
	//û�г�Ա�������߿��࣬���СΪ1��������0��
	//����Ϊ�˴洢���ݣ�����Ϊ��ռλ����ʾ������ڡ�
	system("pause");
	return 0;
}
//thisָ��
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
		this->_day = day;//���Լ���thisָ��

		/*_year = year;
		_month = month;
		_day = day;*/
	}
private:
	int _year; // ��
	int _month; // ��
	int _day; // ��
};
int main()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d2.SetDate(2018, 7, 1);
	//d1.Display(Date *this);//��Ĳ�����д����
	d2.Display();
	return 0;
}
//thisָ���Ƿ����Ϊ��
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
	p->PrintA();//������� //p->PrintA(p)
	p->Show();//��������
	//A a;
	//a.PrintA(); //p->PrintA(&a)
}