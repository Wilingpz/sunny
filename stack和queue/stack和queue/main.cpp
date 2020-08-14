#include<iostream>
#include<stack>
#include<queue>

using namespace std;


int main1()
{
	/*stack<int>a;
	if (a.empty())
	{
		a.push(2);
	}
	cout << "a.size(): "<<a.size() << endl;
	a.push(2);
	a.push(2);
	a.push(6);
	a.pop();
	
	stack<int>b;
	b.push(8);
	b.push(9);
	b.push(10);
	
	b.swap(a);*/
	
	queue<int>a;
	if (a.empty())
	{
		a.push(1);
	}
	cout << a.size() << endl;
	a.push(2);
	a.push(3);
	a.push(4);
	cout << a.back() << " " << a.front() << endl;

	a.pop();
	cout << a.back() << " " << a.front()<<endl;

	queue<int>b;
	b.push(5);
	b.push(6);
	b.push(7);
	b.push(8);
	cout << b.back() << " " << b.front() << endl;;

	b.swap(a);
	cout << b.back() << " " << b.front() << endl;;
	

	system("pause");
	return 0;


}