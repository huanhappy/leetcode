#include "stdafx.h"
#include "listUtil.h"

ListNode* makeList(const std::vector<int>& vec)
{
	if (vec.empty())
		return nullptr;

	ListNode* head = new ListNode(vec.front());
	ListNode* cur = head;
	for (size_t i = 1; i < vec.size(); ++i)
	{
		cur->next = new ListNode(vec[i]);
		cur = cur->next;
	}

	return head;
}

