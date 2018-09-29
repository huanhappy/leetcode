#include "stdafx.h"

// 请判断一个链表是否为回文链表。
// 
// 示例 1:
// 
// 输入 : 1->2
// 输出 : false
// 	 示例 2 :
// 
//  输入 : 1->2->2->1
//   输出 : true
// 	   进阶：
// 	   你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
		if (!head || !head->next)
			return true;

		int len = getLen(head);
		int odd = len % 2 == 1;
		int off = len / 2;

		ListNode* left = head, *pre = nullptr;
		while (off-->0)
		{
			auto next = left->next;
			left->next = pre;
			pre = left;
			left = next;
		}

		if (odd)
			left = left->next;

		while (left && pre)
		{
			if (left->val != pre->val)
				return false;

			left = left->next;
			pre = pre->next;
		}

		return true;

	}
	int getLen(ListNode* head)
	{
		int len = 0;
		while (head)
		{

			head = head->next;
			++len;
		}
		return len;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* head = makeList({ 1, 2 ,2, 1});
	Solution s;
	bool b = s.isPalindrome(head);
	cout << boolalpha << b  << endl;

	return 0;
}

