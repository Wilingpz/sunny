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
int main5()
{
	//C
	int *p1 = NULL;
	//C++11�У��Ƽ�
	int *p2 = nullptr;
	fun(0);//����
	fun(NULL);//���ͣ�Ԥ����� fun(0)
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
	char name[10];
	int age;
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
int main()
{
	Person s1;//��ʵ�����������൱�ڶ��������ĳ�Ա����
	return 0;
}