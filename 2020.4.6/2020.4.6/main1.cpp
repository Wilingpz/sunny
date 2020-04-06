#include<iostream>//数据库连接池
#include<queue>
#include<string>

using namespace std;

int main2()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		queue<char>temp;
		for (int i = 0; i < n; i++)
		{
			char ID;
			cin >> ID;
			string str;
			cin >> str;
			if (str == "connect")
			{
				temp.push(ID);
			}
			else//主要维护历史最大链接数和当前链接数
			{
				count = temp.size() > count ? temp.size() : count;
				temp.pop();
			}//当前最大连接数都在队列里，历史最大连接数为count
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}