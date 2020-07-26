#include<iostream>
using namespace std;

//1、只在堆上创建对象
/*
只能在堆上创建对象----就是阻止在栈上创建空间。
实例化对象有两个过程：开辟空间  和 初始化对象----调用函数意味着在栈
上开辟空间，所以只要阻止初始化，也就是禁止使用构造函数即可-----构造函数私
有化，这样就在类外不能访问构造函数了---但是副作用是即使用new在堆上申请的空
间也无法使用构造函数进行初始化了---和对象没有关系的调用函数是静态函数---所
以在类中可以定义一个静态函数用来实例化对象---防拷贝构造函数（因为可以用堆上
创建一个对象（此时是类类型的 指针变量），对这个变量进行解引用可以得到对象，
用这个对象作为拷贝构造函数的参数，就会造成在栈上也可以创建对象了）---如何防
止调用拷贝构造函数----显式定义出来，编译器就不会生成默认的拷贝构造函数了--
-考虑到如果显式定义的拷贝构造函数给成公有的权限，在类外就能调用这个拷贝构造
函数，所以拷贝构造函数必须给成私有的---由于我们的目的是为了不使用拷贝构造函
数，所以在私有条件下只给声明就行了
*/
class Test
{
	Test()
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
	Test(const Test&);//拷贝构造
	/*c++11新用法：
	Test(const Test& t) = detele;   会使得拷贝构造函数无法生成，也就是告诉编译器将该函数删除掉。
	Test(const Test& t) = default;  告诉编译器，让编译器生成默认的函数*/
public:
	static Test* creat()
	{
		return new Test;//会调用构造函数
	}
};
int main1()
{
	//Test a;  //无法直接构造对象
	Test* a = Test::creat();//成功创建对象
	system("pause");
	return 0;
}
//2、只在栈上创建对象
/*将new的功能屏蔽掉即可，即屏蔽掉operator new 和 定位new表达式*/
class Tmp
{
	void* operator new(size_t size);
	void operator delete(void*p);
public:
	Tmp()
	{
		cout << "Tmp()" << endl;
	}
};