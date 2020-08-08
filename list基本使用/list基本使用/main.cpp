#include<iostream>
#include<list>
using namespace std;

void Print(const list<int>& l)//传入的是一个const对象
{
	//这里迭代器需要用到const_iterator
	//只能访问不能修改
	list<int>::const_iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


class Date
{
	public:
	Date(int year = 1998, int month = 11, int day = 25)
	:_year(year)
	, _month(month)
	, _day(day)
	{
	cout << "全缺省构造" << endl;
	}
	Date(const Date& d)
	:_year(d._year)
	, _month(d._month)
	, _day(d._day)
	{
		cout << "拷贝构造" << endl;
	}
	friend ostream& operator<<(ostream& out, const Date& d);
	private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	//构造函数
	//list<int> a;  //无参
	//list<int>b(5, 3);//n个val
	//list<int>c(b);//拷贝
	////以迭代器指定拷贝位置
	//list<int>::iterator it = c.begin();
	//++it;
	//list<int>d(c.begin(), it);
	//list<int>d(c.begin(), c.end());
	////以数组为迭代器指定拷贝位置
	//int num[] = { 11, 22, 33, 44 };
	//list<int>f(num,num+sizeof(num)/sizeof(int));
	//list<int>f(num, num +2);//包前不包后
	//for (auto &i : f)
	//{
	//	cout << i << ' ';
	//}
	//cout << endl;


	//修改操作
	//push_back 和push_front 头插和尾插
	/*list<int>b(5, 3);
	list<int>e;
	e.push_back(1);
	e.push_back(2);
	e.push_back(3);
	e.push_back(4);
	e.push_front(0);
	e.push_front(-1);
	e.push_front(-2);*/
	/*for (auto &i : e)
	{
		cout << i << ' ';
	}
	cout << endl;*/
	//头删和尾删
	/*e.pop_back();
	e.pop_front();
	Print(e);*/




	//list不支持迭代器加数字确定位置的操作
	//list<int>::iterator pos = find(e.begin(),e.end(),1);
	//if (pos != e.end())
	//{
	//	e.insert(pos, 30);//插入不扩容迭代器不失效
	//	Print(e);
	//	e.insert(pos, b.begin(), b.end());//insert都是在pos位置前进行插入
	//	Print(e);
	//	e.insert(pos, 6, 6);
	//	Print(e);
	//	pos=e.erase(pos);//erase会导致迭代器失效（节点已经被释放）
	//	Print(e);
	//	e.erase(e.begin(),pos);
	//	Print(e);
	//}
	
	//emplace_back/emplace_front/emplace
	/*list<Date>l;
	list<Date>::iterator it = l.begin();
	Date a(2020, 8, 7);
	Date b(2020, 8, 8);
	l.push_back(a);
	l.push_front(b);

	l.emplace_back(2020, 8, 7);
	l.emplace_front(2020, 8, 8);*/
	//push_back先构造好一个Date对像，然后再将Date对象拷贝到链表结点中，插入时先调构造函数，再调拷贝构造
	//emplace_back:先构造结点，然后再调用构造函数在节点中直接构造对象
	
	//swap/resize/clear
	list<int>a(6, 6);
	list<int>b(6, 8);
	b.swap(a);
	cout << "a: ";
	Print(a);
	cout << "b: ";
	Print(b);

	//a.resize(10);
	a.resize(10, 6);
	Print(a);

	a.clear();
	if (a.empty())
	{
		cout << "a已空" << endl;
	}

	//迭代器
	//list<int>::iterator it = e.begin();
	//while (it != e.end())
	//{
	//cout << *it << " ";
	//++it;
	//}
	//cout << endl;
	////反向迭代器
	//list<int>::reverse_iterator rit = e.rbegin();
	//while (rit!=e.rend())
	//{
	//	cout << *rit << " ";
	//	++rit;
	//}
	//cout << endl;

	//容量操作
	/*e.clear();
	if (e.empty())
	{
		cout << "e为空" << endl;
	}
	cout << e.size() << endl;*/
	

	system("pause");
	return 0;
}