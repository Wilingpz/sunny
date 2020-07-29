#include<iostream>
#include<string>

using namespace std;

void test()
{
	//遍历s1的方式
	string s1("hello");
	

	//迭代器
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << endl;//可以读也可以写
	}
	//范围for
	for (auto &i : s1)
	{
		cout << i << endl;
	}
	//常规遍历
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}


	//倒着遍历
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *it << endl;//可以读也可以写
	}

}

void TestString()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}//基本上按照1.5倍增容

void Tset()
{
	string s1;
	//尾插
	s1.push_back('a');
	s1.append("hello!");
	//+=可以追加字符和字符串
	s1 += 'b';
	s1 += "China";
	cout << s1<< endl;
	cout << s1.c_str() << endl;
	//从位置0开始截取6个字符
	string s2 = s1.substr(0, 6);
	cout << s2 << endl;
	/*在中间插入
	string& insert(size_t pos,const char*s);
	string& insert(size_t pos,const string& str);
	*/
	s2.insert(1, "pple");
	cout << "s2: " << s2 << endl;
	s2.insert(0, s1);
	cout << "s2: " << s2 << endl;
	/*
	删除
	string& erase(size_t pos=0,size_t len=pos); 从pos位置开始删除len个字符 
	iterator erase(iterator p);
	iterator erase(iterator first,itreator last);
	*/
	s2.erase(0,12);
	cout << s2 << endl;
	string::iterator it = s2.begin();
	s2.erase(it + 5);
	cout << s2 << endl;
	s2.erase(it, it + s2.size());
	cout << s2;
	if (s2.empty())
	{
		cout << "我是空串" << endl;
	}

	//从某位置向前或向后查找字符
	cout << s1.find('b', 0) << endl;
	cout << s1.rfind('b', s1.size()) << endl;
	cout << s1.find('z', 0) << endl;
}

int main()
{
	Tset();
	system("pause");
	return 0;
}