#include "stdafx.h"

// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// Return a deep copy of the list.
// 
// ����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
// Ҫ�󷵻�����������ȿ�����
// 
/**
* Definition for singly-linked list with a random pointer.
* 
* */

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//  [2018/10/01  created by RockLee]
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return nullptr;

		RandomListNode* _head = head;
		unordered_map<RandomListNode*, RandomListNode*> mapNode;

		mapNode[head] = new RandomListNode(head->label);
		while (head)
		{			
			if (head->random)
			{
				if (nullptr == mapNode[head->random])
					mapNode[head->random] = new RandomListNode(head->random->label);

				mapNode[head]->random = mapNode[head->random];
			}
			if (head->next)
			{
				if (nullptr == mapNode[head->next])
					mapNode[head->next] = new RandomListNode(head->next->label);

				mapNode[head]->next = mapNode[head->next];
			}

			head = head->next;
		}

		return mapNode[_head];
	}
};