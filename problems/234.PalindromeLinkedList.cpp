#include "stdafx.h"

// ���ж�һ�������Ƿ�Ϊ��������
// 
// ʾ�� 1:
// 
// ���� : 1->2
// ��� : false
// 	 ʾ�� 2 :
// 
//  ���� : 1->2->2->1
//   ��� : true
// 	   ���ף�
// 	   ���ܷ��� O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿
// 	   
// Given a singly linked list, determine if it is a palindrome.
// 
// Example 1:
// 
// Input : 1->2
// Output : false
// 		 Example 2 :
// 
// 	 Input : 1->2->2->1
// 		 Output : true
// 				  Follow up :
// 		Could you do it in O(n) time and O(1) space ?
// 		

/**
* Definition for singly-linked list.
* 
**/


class Solution {
public:
	bool isPalindrome(ListNode* head) {
		// zero or one
		if (!head || !head->next)
			return true;

		ListNode* slow = head, *fast = head->next;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		// odd
		const bool odd = (nullptr == fast);
		slow = slow->next;


		ListNode* left = head, *pre = nullptr;
		while (left != slow)
		{
			auto next = left->next;
			left->next = pre;
			pre = left;
			left = next;
		}

		if (odd)
			left = pre->next;
		else
			left = pre;
		
		while (left && slow)
		{
			if (left->val != slow->val)
				return false;

			left = left->next;
			slow = slow->next;
		}

		return true;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* head = makeList({ 1, 2, 5, 2, 1});
	Solution s;
	bool b = s.isPalindrome(head);
	cout << boolalpha << b  << endl;

	return 0;
}

