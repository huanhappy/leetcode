#pragma once


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* makeList(const std::vector<int>& vec);
void printList(ListNode* pNode);