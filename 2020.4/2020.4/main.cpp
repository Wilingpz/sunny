//����һ�������(ransom) �ַ�����һ����־(magazine)�ַ�����
//�жϵ�һ���ַ���ransom�ܲ����ɵڶ����ַ���magazines������ַ����ɡ�
//������Թ��ɣ����� true �����򷵻� false��
//
//(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ��
//��ɵ����������˼��)
//
//ע�⣺
//
//����Լ��������ַ�����ֻ����Сд��ĸ��
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/ransom-note
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution 
{
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		map<int, int>a;
		for (auto &i : magazine)
		{
			a[i]++;
		}
		for (auto &i : ransomNote)//��map�в����ڸ�Ԫ��ʱ�����Զ������������ֵΪ0
		{
			if (--a[i] < 0)//��ʾ������еĸ���ĸ����־�в����ڻ��ߴ��ڵĴ���С��������еĴ���
			{
				return false;
			}
			
		}
		return true;
	}		
};
