#include<iostream>//���ݿ����ӳ�
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
			else//��Ҫά����ʷ����������͵�ǰ������
			{
				count = temp.size() > count ? temp.size() : count;
				temp.pop();
			}//��ǰ������������ڶ������ʷ���������Ϊcount
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}