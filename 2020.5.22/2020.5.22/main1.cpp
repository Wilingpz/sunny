#include <ctime>
#include <iostream>
#include<cstdlib>

class MyRand
{
public:
	unsigned int seed;

	// Ĭ��ʹ��ϵͳʱ��Ϊ����
	// time(NULL) ���ش�1970��Ԫ����ҹ0�㵽���ڵ�����
	void srand(unsigned int s = (unsigned int)time(NULL))
	{
		seed = s;
	}

	// ʹ����һ������ͬ�෨���õ�����������Ϊ(2^15-1),29Ϊ�����е�һ��
	unsigned int rand()
	{
		seed = (seed * 31 + 13) % ((1 << 15) - 1);
		return seed;
	}
};


int main()
{
	MyRand a;

	a.srand();  // ʹ��ϵͳʱ��Ϊ����

	std::cout << "�������ɸ��������" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << a.rand() % 100 << " ";  // ����0~100֮��������

	getchar();
	return 0;
}
