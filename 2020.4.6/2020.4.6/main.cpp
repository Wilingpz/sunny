//makdir
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//����˼·����������ַ�������vector�У�����sort������Ĭ�����򣩶����������
//�Ƚ�ǰһ���ַ����ǲ��Ǳ��ַ������Ӵ�������ɾ����һ������
//�����vector��ÿ��Ԫ��ǰ�����mkdir -p ���д�ӡ����

bool IsSame(string s1, string s2)
{
	if (s1[1] == s2[1])
	{
		s2 = s2.substr(0, s1.size());
		if (s1 == s2)
		{
			return true;
		}
	}
	return false;
}
void mkdir(vector<string>&temp)
{
	int i = 0;
	while (i<temp.size()-1)//��ʱtemp.sizeҲ��ͬ���ڸ���
	{//ǰһ���Ǻ�һ�����Ӵ��Һ�һ������һ���ַ���/
		//vector<string>��������������
		if ((IsSame(temp[i], temp[i + 1])) && temp[i + 1][temp[i].size()] == '/')
		{
			temp.erase(temp.begin()+i);//����ֵ�Ǳ�ɾ��Ԫ�ص���һ��Ԫ�صĵ�����
		}
		else
		{
			i++;
		}
	}
	for (auto &i : temp)
	{
		cout << "mkdir -p " << i << endl;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string>temp;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			temp.push_back(str);
		}
		sort(temp.begin(), temp.end());
		mkdir(temp);
		cout << endl;
	}
	system("pause");
	return 0;
}