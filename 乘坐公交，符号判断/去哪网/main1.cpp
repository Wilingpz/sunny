#include<iostream>
#include<vector>
using namespace std;

/*
��ʱ��=���ϳ�֮ǰ��ʱ��+�ڳ��ϵ�ʱ��
�ڳ��ϵ�ʱ��=��ͣվ����*ͣվʱ��+��ͣվ��+1��*5��

���С��������ʱ��s�պ��Ƿ���ʱ����interval����������˵���ȳ�ʱ��Ϊ0��ʲô��˼����Ϊ���ʱ�䶼�Ǵ�0��ʼ���㣬���������i ������ ʱ����Ϊ30��С������ʱ��60����˵�����õȳ���ֱ�����ڶ��˳���
����Ļ��ȳ�ʱ��Ϊ�������ʱ���ȥ��ʱ��%�������ʱ��
*/
class TakeBuses 
{
public:
	int chooseLine(vector<int> stops, vector<int> period, vector<int> interval, int n, int s) 
		//ͣվ����ͣվʱ�䡢�������������·��������ʱ��
	{
		vector<int>wait_time(n);
		vector<int>run_time(n);
		vector<int>Time(n);
		int MinTime = INT_MAX;
		//ÿһ·������
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