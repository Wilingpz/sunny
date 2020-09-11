#include<iostream>
using namespace std;


struct ListNode
{
	int val;
	struct ListNode *next;
};

class Solution
{
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		ListNode* Node = pHead;
		ListNode* Pprev = nullptr;
		ListNode* Pnext = nullptr;
		ListNode* NewHead = nullptr;


		while (Node != nullptr)//������node�����ڿ�
		{
			Pnext = Node->next;
			if (Pnext == nullptr)//����ͷ
			{
				NewHead = Node;
			}

			Pprev = Node->next;//��תָ��
			Node = Pprev;
			Pnext = Node;
		}

		return  NewHead;
	}
};