//���ʵ���

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
void deal(vector<string>&res, string& str, char delim = ' ') 
{
	stringstream ss;
	//sstringstream������ɶ��ַ������з֣���������ַ���������֮���ת��
	ss << str;
	string tmp;
	while (ss >> tmp) 
	{
		res.push_back(tmp);
	}
}
int main() {
	string str;
	while (getline(cin, str)) 
	{
		vector<string> res;
		for (int i = 0; i < str.size(); i++)
		{
			if (!isalnum(str[i]))//�ж����Ƿ�Ϊ��ĸ������
			{
				str[i] = ' ';
			}
		}
		deal(res, str);
		cout << res[res.size() - 1];
		for (int i = res.size() - 2; i >= 0; i--)
		{
			cout << " " << res[i];
		}
		cout << endl;
	}
	return 0;
}













//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		for (auto &i : str)
//		{
//			if (!((i >= 'A'&&i <= 'Z') ||
//				(i >= 'a'&&i <= 'z')))
//			{
//				i = ' ';
//			}
//		}
//
//	}
//}