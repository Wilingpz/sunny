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
	// ���뵥��Test���͵Ķ���
	Test* p1 = new Test;
	delete p1;
	// ����10��Test���͵Ķ���
	Test* p2 = new Test[10];
	delete[] p2;
}
int main()
{
	Test2();
	system("pause");
	return 0;

}