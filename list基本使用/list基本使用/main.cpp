#include<iostream>
#include<list>
using namespace std;

void Print(const list<int>& l)//�������һ��const����
{
	//�����������Ҫ�õ�const_iterator
	//ֻ�ܷ��ʲ����޸�
	list<int>::const_iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


class Date
{
	public:
	Date(int year = 1998, int month = 11, int day = 25)
	:_year(year)
	, _month(month)
	, _day(day)
	{
	cout << "ȫȱʡ����" << endl;
	}
	Date(const Date& d)
	:_year(d._year)
	, _month(d._month)
	, _day(d._day)
	{
		cout << "��������" << endl;
	}
	friend ostream& operator<<(ostream& out, const Date& d);
	private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	//���캯��
	//list<int> a;  //�޲�
	//list<int>b(5, 3);//n��val
	//list<int>c(b);//����
	////�Ե�����ָ������λ��
	//list<int>::iterator it = c.begin();
	//++it;
	//list<int>d(c.begin(), it);
	//list<int>d(c.begin(), c.end());
	////������Ϊ������ָ������λ��
	//int num[] = { 11, 22, 33, 44 };
	//list<int>f(num,num+sizeof(num)/sizeof(int));
	//list<int>f(num, num +2);//��ǰ������
	//for (auto &i : f)
	//{
	//	cout << i << ' ';
	//}
	//cout << endl;


	//�޸Ĳ���
	//push_back ��push_front ͷ���β��
	/*list<int>b(5, 3);
	list<int>e;
	e.push_back(1);
	e.push_back(2);
	e.push_back(3);
	e.push_back(4);
	e.push_front(0);
	e.push_front(-1);
	e.push_front(-2);*/
	/*for (auto &i : e)
	{
		cout << i << ' ';
	}
	cout << endl;*/
	//ͷɾ��βɾ
	/*e.pop_back();
	e.pop_front();
	Print(e);*/




	//list��֧�ֵ�����������ȷ��λ�õĲ���
	//list<int>::iterator pos = find(e.begin(),e.end(),1);
	//if (pos != e.end())
	//{
	//	e.insert(pos, 30);//���벻���ݵ�������ʧЧ
	//	Print(e);
	//	e.insert(pos, b.begin(), b.end());//insert������posλ��ǰ���в���
	//	Print(e);
	//	e.insert(pos, 6, 6);
	//	Print(e);
	//	pos=e.erase(pos);//erase�ᵼ�µ�����ʧЧ���ڵ��Ѿ����ͷţ�
	//	Print(e);
	//	e.erase(e.begin(),pos);
	//	Print(e);
	//}
	
	//emplace_back/emplace_front/emplace
	/*list<Date>l;
	list<Date>::iterator it = l.begin();
	Date a(2020, 8, 7);
	Date b(2020, 8, 8);
	l.push_back(a);
	l.push_front(b);

	l.emplace_back(2020, 8, 7);
	l.emplace_front(2020, 8, 8);*/
	//push_back�ȹ����һ��Date����Ȼ���ٽ�Date���󿽱����������У�����ʱ�ȵ����캯�����ٵ���������
	//emplace_back:�ȹ����㣬Ȼ���ٵ��ù��캯���ڽڵ���ֱ�ӹ������
	
	//swap/resize/clear
	list<int>a(6, 6);
	list<int>b(6, 8);
	b.swap(a);
	cout << "a: ";
	Print(a);
	cout << "b: ";
	Print(b);

	//a.resize(10);
	a.resize(10, 6);
	Print(a);

	a.clear();
	if (a.empty())
	{
		cout << "a�ѿ�" << endl;
	}

	//������
	//list<int>::iterator it = e.begin();
	//while (it != e.end())
	//{
	//cout << *it << " ";
	//++it;
	//}
	//cout << endl;
	////���������
	//list<int>::reverse_iterator rit = e.rbegin();
	//while (rit!=e.rend())
	//{
	//	cout << *rit << " ";
	//	++rit;
	//}
	//cout << endl;

	//��������
	/*e.clear();
	if (e.empty())
	{
		cout << "eΪ��" << endl;
	}
	cout << e.size() << endl;*/
	

	system("pause");
	return 0;
}