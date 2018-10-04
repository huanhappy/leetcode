#include "stdafx.h"

// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// Return a deep copy of the list.
// 
// 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
// 要求返回这个链表的深度拷贝。
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

	// first edition: hash_map
	// time: 40ms
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


	// from leetcode [2018/10/03  created by RockLee]
	// time : 36ms
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return nullptr;

		RandomListNode* p = head;
		while (p)
		{
			RandomListNode* pcpy = new RandomListNode(p->label);
			pcpy->next = p->next;
			p->next = pcpy;
			p = pcpy->next;
		}

		p = head;
		while (p)
		{
			RandomListNode* cpy = p->next;
			RandomListNode* tmp = p->next->next;
			if (nullptr != p->random)
				cpy->random = p->random->next;

			p = tmp;
		}

		p = head;
		RandomListNode* newHead = p->next, *p2 = p->next;
		while (p2)
		{
			p->next = p2->next;
			if (p2->next == nullptr)
				break;

			p2->next = p2->next->next;
			p = p->next;
			p2 = p2->next
		}

		return newHead;
	}

	// use hash_map, twice loop [2018/10/03  created by RockLee]
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		if (!head)
			return NULL;
		RandomListNode *res = new RandomListNode(head->label);
		RandomListNode *node = res;
		RandomListNode *cur = head->next;
		map<RandomListNode*, RandomListNode*> m;
		m[head] = res;
		while (cur)
		{
			RandomListNode *tmp = new RandomListNode(cur->label);
			m[cur] = tmp;
			node->next = tmp;
			cur = cur->next;
			node = node->next;
		}

		node = res;
		cur = head;
		while (cur)
		{
			node->random = m[cur->random];
			cur = cur->next;
			node = node->next;
		}
		return res;
	}

};