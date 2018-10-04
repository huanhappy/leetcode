#include "stdafx.h"

// Given a linked list, rotate the list to the right by k places, where k is non - negative.
// ����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����
// 
// ʾ�� 1:
// 
// ���� : 1->2->3->4->5->NULL, k = 2
// ��� : 4->5->1->2->3->NULL
//  ���� :
// ������ת 1 �� : 5->1->2->3->4->NULL
// ������ת 2 �� : 4->5->1->2->3->NULL
// ʾ�� 2 :
// 
// ���� : 0->1->2->NULL, k = 4
//  ��� : 2->0->1->NULL
//   ���� :
// ������ת 1 �� : 2->0->1->NULL
// ������ת 2 �� : 1->2->0->NULL
// ������ת 3 �� : 0->1->2->NULL
// ������ת 4 �� : 2->0->1->NULL

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (nullptr == head)
			return nullptr;

		int len = 0;
		ListNode* p = head;
		while (p->next)
		{
			++len;
			p = p->next;
		}

		ListNode* tail = p;
		++len;

		k %= len;
		if (k == 0)
			return head;

		k = len - k;
		p = head;
		while (k > 1)
		{
			p = p->next;
			--k;
		}

		auto p1 = p->next;
		p->next = nullptr;

		tail->next = head;
		return p1;
	}
};

int main()
{
	auto list = makeList({ 1, 2, 3, 4, 5 });
	printList(list);

	Solution s;
	auto r = s.rotateRight(list, 2);
	printList(r);

	return 0;
}