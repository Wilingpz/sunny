#include<iostream>
#include<string>

using namespace std;

void test()
{
	//����s1�ķ�ʽ
	string s1("hello");
	

	//������
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << endl;//���Զ�Ҳ����д
	}
	//��Χfor
	for (auto &i : s1)
	{
		cout << i << endl;
	}
	//�������
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}


	//���ű���
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *it << endl;//���Զ�Ҳ����д
	}

}

void TestString()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}//�����ϰ���1.5������

void Tset()
{
	string s1;
	//β��
	s1.push_back('a');
	s1.append("hello!");
	//+=����׷���ַ����ַ���
	s1 += 'b';
	s1 += "China";
	cout << s1<< endl;
	cout << s1.c_str() << endl;
	//��λ��0��ʼ��ȡ6���ַ�
	string s2 = s1.substr(0, 6);
	cout << s2 << endl;
	/*���м����
	string& insert(size_t pos,const char*s);
	string& insert(size_t pos,const string& str);
	*/
	s2.insert(1, "pple");
	cout << "s2: " << s2 << endl;
	s2.insert(0, s1);
	cout << "s2: " << s2 << endl;
	/*
	ɾ��
	string& erase(size_t pos=0,size_t len=pos); ��posλ�ÿ�ʼɾ��len���ַ� 
	iterator erase(iterator p);
	iterator erase(iterator first,itreator last);
	*/
	s2.erase(0,12);
	cout << s2 << endl;
	string::iterator it = s2.begin();
	s2.erase(it + 5);
	cout << s2 << endl;
	s2.erase(it, it + s2.size());
	cout << s2;
	if (s2.empty())
	{
		cout << "���ǿմ�" << endl;
	}

	//��ĳλ����ǰ���������ַ�
	cout << s1.find('b', 0) << endl;
	cout << s1.rfind('b', s1.size()) << endl;
	cout << s1.find('z', 0) << endl;
}

int main()
{
	Tset();
	system("pause");
	return 0;
}