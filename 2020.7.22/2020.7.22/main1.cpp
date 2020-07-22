#include<iostream>
using namespace std;

class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
void Test2()
{
	// 申请单个Test类型的对象
	Test* p1 = new Test;
	delete p1;
	// 申请10个Test类型的对象
	Test* p2 = new Test[10];
	delete[] p2;
}
int main()
{
	Test2();
	system("pause");
	return 0;

}