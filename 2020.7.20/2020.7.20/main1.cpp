//实现一个类，计算类一共创建了多少个对象
#include<iostream>
using namespace std;

class temp
{
	static int a;
public:
	temp()
	{
		++a;
	}
	temp(temp& b)
	{
		++a;
	}
	 static int GetA()
	{
		 return a;
	}
    /*friend ostream& operator <<(ostream &out, const temp &a);*/
};
//ostream& operator <<(ostream &out, const temp &a)
//{
//	out <<a.a << endl;
//	return out;
//}
int temp::a = 0;
int main3()
{
	cout << temp::GetA() << endl;
	temp a;
	temp b;
	temp c;
	temp d(a);
	cout << temp::GetA() << endl;
	system("pause");
	return 0;
}
