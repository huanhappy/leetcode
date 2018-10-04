#include "stdafx.h"

// Given a linked list, rotate the list to the right by k places, where k is non - negative.
// 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
// 
// 示例 1:
// 
// 输入 : 1->2->3->4->5->NULL, k = 2
// 输出 : 4->5->1->2->3->NULL
//  解释 :
// 向右旋转 1 步 : 5->1->2->3->4->NULL
// 向右旋转 2 步 : 4->5->1->2->3->NULL
// 示例 2 :
// 
// 输入 : 0->1->2->NULL, k = 4
//  输出 : 2->0->1->NULL
//   解释 :
// 向右旋转 1 步 : 2->0->1->NULL
// 向右旋转 2 步 : 1->2->0->NULL
// 向右旋转 3 步 : 0->1->2->NULL
// 向右旋转 4 步 : 2->0->1->NULL

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