#pragma once
#include<vector>

namespace pz
{
	template<class T,class Container = vector<T>,class Compare = less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(int child)//向上调整，大堆
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child>0)
			{
				//if (_con[child] > _con[parent]);
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustDdown(int root)//向下调整 
		{
	
			int parent = root;
			int child = parent * 2 + 1;
			Compare com;

			while (child<_con.size())
			{
				//if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				if (child + 1 < _con.size() && com(_con[child],_con[child+1]))
				{
					++child;
				}
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}


		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);//向上调整算法

		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			AdjustDown(0);
		}
		T& top()
		{
			return _con[0];
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;

	};
	void test()
	{
		priority_queue<int>a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.push(4);
		a.push(5);
		while (!a.empty())
		{
			cout << a.top() << " ";
			a.pop();
		}
		cout << endl;
	}
}