#include<iostream>
#include<vector>
using namespace std;

/*
总时间=坐上车之前的时间+在车上的时间
在车上的时间=（停站数）*停站时间+（停站数+1）*5；

如果小明出发的时间s刚好是发车时间间隔interval的整数倍，说明等车时间为0，什么意思？因为相对时间都是从0开始计算，例如如果第i 条发车 时间间隔为30，小明出发时间60，则说明不用等车，直接坐第二趟车。
否则的话等车时间为发车间隔时间减去起床时间%发车间隔时间
*/
class TakeBuses 
{
public:
	int chooseLine(vector<int> stops, vector<int> period, vector<int> interval, int n, int s) 
		//停站数、停站时间、发车间隔、公交路数、发车时间
	{
		vector<int>wait_time(n);
		vector<int>run_time(n);
		vector<int>Time(n);
		int MinTime = INT_MAX;
		//每一路汽车的
		for (int i = 0; i < n; i++)
		{
			if (s%interval[i] == 0)
			{
				wait_time[i] = 0;
			}
			else
			{
				wait_time[i] = interval[i] - s%interval[i];
			}
			run_time[i] = (stops[i] + 1) * 5 + period[i] * stops[i];
			Time[i] = s+wait_time[i] + run_time[i];

			if (Time[i] < MinTime)
			{
				MinTime = Time[i];
			}
		}
		return MinTime;
	}
};