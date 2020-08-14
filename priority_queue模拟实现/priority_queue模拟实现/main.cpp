#include<iostream>
#include"priority_queue.h"
using namespace std;

namespace pz
{
	template<class T>//仿函数
	struct less//小于号  大堆
	{
		bool operator()(const T & x1, const T& x2)
		{
			return x1 < x2;
		}
	};

	template<class T>
	struct greater//大于号  小堆
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1>x2;
		}
	};
}




int main()
{
	 pz::test();
	 
	 system("pause");
	 return 0;
}