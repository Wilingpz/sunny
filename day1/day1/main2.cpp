#include<iostream>
#include<vector>
using namespace std;
//��β��ͷ��ӡ����
#if 1 
struct ListNode {
	int val;
	struct ListNode *next;
	 
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) 
	{
		vector<int>res;
		while (head)
		{
			res.push_back(head->val);
			head = head->next;
		}
		reverse(res.begin(), res.end());
		
		return res;
	}
};
//��ת����
#else
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head)
	{
		ListNode* pre = nullptr;
		ListNode*cur = head;
		ListNode* temp = cur;
		while (cur)
		{
			temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		vector<int>res;
		while (head)
		{
			res.push_back(head->val);
			head = head->next;
		}
		
		return res;
	}
};
#endif

