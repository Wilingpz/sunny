#include<iostream>
using namespace std;

class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}
	};
};
int A::k = 1;
int main1()
{
	A a;
	A::B b;
	b.foo(A());
	cout << sizeof(a) << endl;//4, static²»Ëã
	cout<<sizeof(b)<<endl;//1
	system("pause");
	return 0;
}
