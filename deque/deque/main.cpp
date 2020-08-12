#include<iostream>
#include<deque>
#include<list>
#include<vector>
using namespace std;

void Print(const deque<int>& tmp)
{
	for (auto &i : tmp)
	{
		cout << i << " ";
	}
	cout << endl;
}
int main()
{
	//构造

	deque<int>a;
	deque<int>b(6, 6);
	
	int m[6] = { 9, 9, 9, 9, 9, 9 };
	deque<int>c(m, m + 4);//包前不包后
	deque<int>d(b.begin(), b.end());

	deque<int>e(d);

	//迭代器
	/*deque<int>::iterator  it = e.begin();
	while (it!=e.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	deque<int>::reverse_iterator  it1 = e.rbegin();
	while (it1!=e.rend())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
*/

	//容量操作
	//if (e.empty())
	//{
	//	cout << "i'm empty!" << endl;
	//}
	//else
	//{
	//	cout << "i'm full!" << endl;
	//}

	//cout << e.size() << endl;//6
	//e.resize(10);
	//cout << e.size() << endl;//10,用0补全的
	//Print(e);

	//元素访问
	/*for (int i = 0; i < e.size(); ++i)
	{
		cout << e[i] << " ";
	}
	cout << endl;

	cout << e.front() << endl;
	cout << e.back() << endl;
	Print(e);*/
	
	//修改操作
	e.push_back(8);
	Print(e);
	e.push_front(8);
	Print(e);
	
	e.pop_back();
	Print(e);
	e.pop_front();
	Print(e);

	e.insert(e.begin() + 2, 2);
	Print(e);
	e.insert(e.begin() + 2, 2,2);
	Print(e);
	e.insert(e.begin(), c.begin(), c.end());
	Print(e);
	e.erase(e.begin());
	Print(e);
	e.erase(e.begin(), e.begin() + 3);
	Print(e);

	e.swap(c);
	Print(e);
	e.emplace_back(0);
	Print(e);
	e.emplace_front(6);
	Print(e);



	system("pause");
	return 0;
}