#include<iostream>
#include"priority_queue.h"
using namespace std;

namespace pz
{
	template<class T>//�º���
	struct less//С�ں�  ���
	{
		bool operator()(const T & x1, const T& x2)
		{
			return x1 < x2;
		}
	};

	template<class T>
	struct greater//���ں�  С��
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