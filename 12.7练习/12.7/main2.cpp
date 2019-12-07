#include<iostream>//±äÌ¬ÇàÍÜÌøÌ¨½×
using namespace std;

class Solution 
{
public:
	int jumpFloorII(int number) 
	{
		int num = 0;
		if (number == 0)
		{
			return 0;
		}
		if (number == 1)
		{
			return 1;
		}
		return num = 2*jumpFloorII(number-1);
	}
};