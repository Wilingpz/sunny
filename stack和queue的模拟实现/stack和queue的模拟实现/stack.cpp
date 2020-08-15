#include<iostream>
#include<deque>


template <class T, class Con = std::deque<T>>
class Stack
{
public:
	Stack() {}

	void push(const T&x)
	{
		_con.push_back(x);
	}

	void pop()
	{
		_con.pop_back();
	}

	T& Top()
	{
		return _con.back();
	}

	const T& Top()const
	{
		return _c.back();
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

void test()
{
	Stack<int,std::deque<int>>a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);

	std::cout << a.Size() << std::endl;
	std::cout << a.Top() << std::endl;

	a.pop();
	a.pop();

	std::cout << a.Size() << std::endl;
	std::cout << a.Top() << std::endl;
}

int main1()
{
	test();
	system("pause");
	return 0;
}