#include<iostream>
#include<map>
using namespace std;
int main9()
{
	int n;
	int k;
	while (cin >> n)
	{
		map<int, int>tmp;
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			tmp[t] = 1;
		}
		cin >> k;
		 auto it = tmp.begin();
		 for (; it != tmp.end()&&k!=1; ++it, --k)//k=1时输出当前map的值
		 {
		 }
		 cout << it->first << endl;
	}
	return 0;
}