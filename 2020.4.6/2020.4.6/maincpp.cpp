//一种消息接收并打印的结构设计
#include<iostream>
#include<vector>
#include<map>

using namespace std;
class Node
{
public:
	int num;
	Node* next;
	Node(int num) :
		num(num)
	{};
};
class Mystr
{
public:
	map<int, Node*>headMap;
	map<int, Node*>tailMap;
	int wait;
public:
	Mystr() :
		headMap(),
		tailMap(),
		wait(0)
	{};
	void receive(int a);
	void print();

};
void Mystr::receive(int a)
{
	if (a < 1)
	{
		return;
	}
	Node* cur = new Node(a);
	headMap[a] = cur;
	tailMap[a] = cur;
	if (headMap.count(a + 1) == 1)//如果headmap中存在a+1
	{
		cur->next = headMap[a + 1];
		headMap.erase(a + 1);
		tailMap.erase(a);
	}
	if (tailMap.count(a - 1) == 1)//如果tailmap中存在a-1
	{
		tailMap[a - 1]->next = cur;
		tailMap.erase(a - 1);
		headMap.erase(a);
	}
	if (headMap.find(wait + 1) != headMap.end())
	{
		print();
	}
}
void Mystr::print()
{
	int cur = wait;
	Node* node = headMap.at(++wait);
	while (node != NULL)
	{
		cout << node->num << " " << cur + 1 << endl;
		wait++;
	}
	tailMap.erase(--wait);
}
int main1()
{
	int n;
	cin >> n;
	vector<int>a(n);
	Mystr s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s.receive(a[i]);
	}
	system("pause");
	return 0;
}