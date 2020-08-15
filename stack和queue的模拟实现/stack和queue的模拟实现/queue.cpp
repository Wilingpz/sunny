#include<deque>
#include<iostream>

template <class T, class Con = std::deque<T>>
class queue
{
public:
	queue(){}
	void push_back(const T& x)
	{
		 _con.push_back(x);
	}
	void pop_front()
	{
		 _con.pop_front();
	}
	T& back()
	{
		return _con.back();
	}
	T& front()
	{
		return _con.front();
	}
	const T& back()const 
	{
		return _con.back();
	}
	const T& front()const
	{
		return _con.front();
	}
	size_t Size()
	{
		return _con.size();
	}
	bool empty()
	{
		return _con.empty();
	}
private:
	Con _con;
};


void test1()
{
	queue<int>a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	std::cout << a.Size() << std::endl;
	std::cout << a.front() << std::endl;
	std::cout << a.back() << std::endl;

	a.pop_front();
	std::cout << a.Size() << std::endl;
	std::cout << a.front() << std::endl;
	std::cout << a.back() << std::endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}