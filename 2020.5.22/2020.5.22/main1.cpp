#include <ctime>
#include <iostream>
#include<cstdlib>

class MyRand
{
public:
	unsigned int seed;

	// 默认使用系统时间为种子
	// time(NULL) 返回从1970年元旦午夜0点到现在的秒数
	void srand(unsigned int s = (unsigned int)time(NULL))
	{
		seed = s;
	}

	// 使用了一种线性同余法，得到的随机数最大为(2^15-1),29为质数中的一个
	unsigned int rand()
	{
		seed = (seed * 31 + 13) % ((1 << 15) - 1);
		return seed;
	}
};


int main()
{
	MyRand a;

	a.srand();  // 使用系统时间为种子

	std::cout << "产生若干个随机数：" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << a.rand() % 100 << " ";  // 生成0~100之间的随机数

	getchar();
	return 0;
}
