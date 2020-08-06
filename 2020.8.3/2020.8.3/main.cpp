#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main1()
{
	//构造函数
	//vector<int>a;
	//vector<int>b(8, 6);//8个6
	//vector<int>c(b);//拷贝构造
	//vector<int>d(c.begin() + 2, c.end());
	//for (auto &i : d)
	//{
	//	cout << i << endl;
	//}
//迭代器构造
	/*int n[] = { 16, 2, 77, 29 };
	vector<int> e(n, n + sizeof(n) / sizeof(int));
	cout << "The contents of fifth are:";
	for (vector<int>::iterator it = e.begin(); it != e.end(); ++it)
	{
		cout << ' ' << *it;
	}*/
//空间增长
	/*vector<int>a;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}
	for (int i = 0; i < a.size(); i++)
	{
		cout<<a[i];
	};
	cout << endl;


	a.resize(5);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	};
	cout << endl;


	a.resize(8, 100);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	};
	cout << endl;


	a.resize(12);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	};
	cout << endl;*/
	////a.reserve(100);
	//cout << a.capacity() << endl;
	//int sz = a.capacity();
	//for (int i = 0; i < 100; i++)
	//{
	//	a.push_back(i);
	//	if (sz != a.capacity())
	//	{
	//		sz = a.capacity();
	//		cout << "capacity变化为： " << sz << endl;
	//	}
	//}

//增删修改
	//vector<int>v;
	//for (int i = 0; i < 10; i++)
	//{
	//	v.push_back(i);
	//}
	//cout << "v的原始数据： ";
	//for (auto &i : v)
	//{
	//	cout << i;
	//}
	//cout << endl;//0123456789
	////不是成员函数，返回迭代器
	//vector<int>::iterator pos = find(v.begin(), v.end(), 6);
	//cout << *pos << endl;//6



	//v.pop_back();
	//v.pop_back();
	//cout << "v pop_back()两次后数据： ";
	//for (auto &i : v)
	//{
	//	cout << i;
	//}
	//cout << endl;
	//v.insert(v.begin()+1, 6);//在pos位置之前插入
	//cout << "v 插入一次后数据： ";
	//for (auto &i : v)
	//{
	//	cout << i;
	//}
	//cout << endl;
	//v.erase(v.begin() + 1);
	//cout << "v 删除一次后数据： ";
	//for (auto &i : v)
	//{
	//	cout << i;
	//}
	//cout << endl;

	//vector<int>s(6, 0);
	//s.swap(v);
	//cout << "s和v交换空间后数据： ";
	//for (int i = 0; i < s.size(); i++)
	//{
	//	cout << s[i];
	//}
	//cout << endl;

	//迭代器失效
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//vector<int>::iterator pos = find(v.begin(), v.end(), 6);
	////1、删除pos位置数据，迭代器失效
	//v.erase(pos);
	////cout << *pos << endl;//非法访问
	//for (auto &i : v)
	//{
	//	cout << i << endl;
	//}
	////2、insert会导致增容，增容后pos还指向原来的空间
	////可是原空间已经释放了，会导致迭代器失效
	//pos = find(v.begin(), v.end(), 1);
	//v.insert(pos, 30);
	//cout << *pos << endl;//非法访问

//解决迭代器失效问题
//vector<int>::iterator it = v.begin();
//while (it != v.end)
//{
//	if (*it % 2 == 0)
//	{
//		it=v.erase(it);//返回删除位置的下一个位置迭代器
//	}
//	it++;
//
//}
	system("pause");
	return 0;
}