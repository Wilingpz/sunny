//����������
#include<iostream>
#include<string>
using namespace std;

int main1()
{
	string temp;
	while (cin >> temp)
	{
		int k = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == '_')
			{
				temp.erase(temp.begin()+i);
				temp[i] = temp[i] - 32;
			}
		}
		cout << temp << endl;
		system("pause");
	}
	return 0;
}


//string��erase�������÷�
//1��string &erase��size_t pos=0,size_t n=npos��ɾ����posλ�ÿ�ʼ��n���ַ�
//2��iterator erase��position��;ɾ��positionλ�ô����ַ���position��string���͵ĵ�������
//3��erase��iterator first��iterator last��;ɾ����first��last֮����ַ�
//