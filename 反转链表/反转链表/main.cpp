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


		while (Node != nullptr)//条件是node不等于空
		{
			Pnext = Node->next;
			if (Pnext == nullptr)//赋新头
			{
				NewHead = Node;
			}

			Pprev = Node->next;//反转指向
			Node = Pprev;
			Pnext = Node;
		}

		return  NewHead;
	}
};