#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main1()
{
	//���캯��
	//vector<int>a;
	//vector<int>b(8, 6);//8��6
	//vector<int>c(b);//��������
	//vector<int>d(c.begin() + 2, c.end());
	//for (auto &i : d)
	//{
	//	cout << i << endl;
	//}
//����������
	/*int n[] = { 16, 2, 77, 29 };
	vector<int> e(n, n + sizeof(n) / sizeof(int));
	cout << "The contents of fifth are:";
	for (vector<int>::iterator it = e.begin(); it != e.end(); ++it)
	{
		cout << ' ' << *it;
	}*/
//�ռ�����
	/*vector<int>a;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}
	for (int i = 0; i < a.size(); i++)
	{
		cout<<a[i];
	};
	cout << endl;


	a.resize(5);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	};
	cout << endl;


	a.resize(8, 100);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	};
	cout << endl;


	a.resize(12);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	};
	cout << endl;*/
	////a.reserve(100);
	//cout << a.capacity() << endl;
	//int sz = a.capacity();
	//for (int i = 0; i < 100; i++)
	//{
	//	a.push_back(i);
	//	if (sz != a.capacity())
	//	{
	//		sz = a.capacity();
	//		cout << "capacity�仯Ϊ�� " << sz << endl;
	//	}
	//}

//��ɾ�޸�
	//vector<int>v;
	//for (int i = 0; i < 10; i++)
	//{
	//	v.push_back(i);
	//}
	//cout << "v��ԭʼ���ݣ� ";
	//for (auto &i : v)
	//{
	//	cout << i;
	//}
	//cout << endl;//0123456789
	////���ǳ�Ա���������ص�����
	//vector<int>::iterator pos = find(v.begin(), v.end(), 6);
	//cout << *pos << endl;//6



	//v.pop_back();
	//v.pop_back();
	//cout << "v pop_back()���κ����ݣ� ";
	//for (auto &i : v)
	//{
	//	cout << i;
	//}
	//cout << endl;
	//v.insert(v.begin()+1, 6);//��posλ��֮ǰ����
	//cout << "v ����һ�κ����ݣ� ";
	//for (auto &i : v)
	//{
	//	cout << i;
	//}
	//cout << endl;
	//v.erase(v.begin() + 1);
	//cout << "v ɾ��һ�κ����ݣ� ";
	//for (auto &i : v)
	//{
	//	cout << i;
	//}
	//cout << endl;

	//vector<int>s(6, 0);
	//s.swap(v);
	//cout << "s��v�����ռ�����ݣ� ";
	//for (int i = 0; i < s.size(); i++)
	//{
	//	cout << s[i];
	//}
	//cout << endl;

	//������ʧЧ
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//vector<int>::iterator pos = find(v.begin(), v.end(), 6);
	////1��ɾ��posλ�����ݣ�������ʧЧ
	//v.erase(pos);
	////cout << *pos << endl;//�Ƿ�����
	//for (auto &i : v)
	//{
	//	cout << i << endl;
	//}
	////2��insert�ᵼ�����ݣ����ݺ�pos��ָ��ԭ���Ŀռ�
	////����ԭ�ռ��Ѿ��ͷ��ˣ��ᵼ�µ�����ʧЧ
	//pos = find(v.begin(), v.end(), 1);
	//v.insert(pos, 30);
	//cout << *pos << endl;//�Ƿ�����

//���������ʧЧ����
//vector<int>::iterator it = v.begin();
//while (it != v.end)
//{
//	if (*it % 2 == 0)
//	{
//		it=v.erase(it);//����ɾ��λ�õ���һ��λ�õ�����
//	}
//	it++;
//
//}
	system("pause");
	return 0;
}