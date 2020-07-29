#include<iostream>
#include<vector>
using namespace std;

// �ַ�������
#if 1
class Solution
{
public:
	void reverseString(vector<char>& s)
	{
		int i = 0, j = s.size() - 1;
		while (j>i)
		{
			swap(s[i], s[j]);
			i++;
			j--;
		}

	}
};
#else
class Solution
{
public:
	void reverseString(vector<char>& s)
	{
		reverse(s.begin(), s.end());
	}
};
#endif

int main1()
{
	Solution a;
	vector<char>s;
	s.push_back('h');
	s.push_back('e'); 
	s.push_back('l'); 
	s.push_back('l'); 
	s.push_back('o'); 
	a.reverseString(s);
	for (auto &i : s)
	{
		cout << i;
	}
	system("pause");
	return 0;
}

//�ַ����е�һ�����ֵ�Ψһ�ַ�

int firstUniqChar(string s) {
	int cout[256] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		if (s.find(s[i], 0) == s.rfind(s[i], s.size()))
		{
			return i;
		}
	}
	return -1;
}