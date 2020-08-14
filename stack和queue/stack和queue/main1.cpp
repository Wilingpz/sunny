#include<iostream>
#include<queue>//priority_queue需要包含的头文件
#include<vector>
#include<functional>//greater算法的头文件,默认是大堆

using namespace std;

void test()
{
	priority_queue<int>q;//默认是大堆 less
	
	vector<int>v = { 1, 2, 3, 4, 5, 6, 7 };
	priority_queue<int>a(v.begin(), v.end());
	while (!a.empty())
	{
		cout << a.top()<<" ";
		a.pop();
	}
	cout << endl;//结果：7,6,5,4,3,2,1

	a.push(10);
	a.push(0);
	a.push(1);
	a.push(1);//可以有相同元素的存在
	while (!a.empty())
	{
		cout << a.top() << " ";
		a.pop();
	}
	cout << endl;

	//建小堆
	priority_queue<int, vector<int>, greater<int>>b(v.begin(),v.end());//小堆
	while (!b.empty())
	{
		cout << b.top() << " ";
		b.pop();
	}
	cout << endl;
	priority_queue<int, vector<int>, less<int>>c(v.begin(), v.end());//默认大堆
	while (!c.empty())
	{
		cout << c.top() << " ";
		c.pop();
	}
	cout << endl;

}
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};

class Less
{
public:
	bool operator()(const Date* pLeft, const Date* pRight)
	{
		return *pLeft < *pRight;
	}
};
void TestPriorityQueue()
{
	// 自己定制比较的规则
	priority_queue<Date*, vector<Date*>, Less> q;
	q.push(&Date(2018, 10, 29));
	q.push(&Date(2018, 10, 28));
	q.push(&Date(2018, 10, 30));
	cout << *q.top() << endl;
}
int main()
{
	
	system("pause");
	return 0;
}