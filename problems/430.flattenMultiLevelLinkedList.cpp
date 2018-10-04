#include "stdafx.h"

// ��ƽ���༶˫������
// 
// You are given a doubly linked list which in addition to the next and previous pointers,
// it could have a child pointer, which may or may not point to a separate doubly linked list.
// These child lists may have one or more children of their own, and so on, 
// to produce a multilevel data structure, as shown in the example below.
// 
// Flatten the list so that all the nodes appear in a single - level, 
// doubly linked list.You are given the head of the first level of the list.
// 
// Example:
// 
// Input :
// 	1-- - 2-- - 3-- - 4-- - 5-- - 6--NULL
// 	            |
// 	            7-- - 8-- - 9-- - 10--NULL
// 	                  |
// 	                  11--12--NULL
// 
// Output :
// 	  1 - 2 - 3 - 7 - 8 - 11 - 12 - 9 - 10 - 4 - 5 - 6 - NULL
// 		  Explanation for the above example :
// 
// 	  Given the following multilevel doubly linked list :
// 	  
// �������һ��˫������������һ����ǰһ��ָ��֮�⣬������һ����ָ�룬����ָ�򵥶���˫������
// ��Щ���б������һ�������Լ�������������ƣ����ɶ༶���ݽṹ���������ʾ����ʾ��
// 
// ��ƽ���б�ʹ���н������ڵ���˫�����С���������б��һ����ͷ����
// 

/*
// Definition for a Node.*/
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
	//  [2018/10/03  created by RockLee]
	Node* flatten(Node* head) {
		if (nullptr == head)
			return nullptr;

		Node* pnewHead = new Node();
		Node* pNewHeadBack = pnewHead;
		DoFlaten(head, pnewHead);
		pNewHeadBack->next->prev = nullptr;
		return pNewHeadBack->next;  
    }

	//  [2018/10/03  created by RockLee]
	void DoFlaten(Node* head, Node*& pnewHead)
	{
		while (head)
		{
			auto* newNode = new Node(head->val, pnewHead, nullptr, nullptr);
			pnewHead = pnewHead->next = newNode;
			
			if (head->child)
				DoFlaten(head->child, pnewHead);

			head = head->next;
		}
	}
};

Node* createList(const vector<int>& vec)
{
	Node n;
	Node* pNode = &n;
	for (auto v : vec)
	{
		Node* p = new Node(v, pNode, nullptr, nullptr);
		pNode->next = p;

		pNode = p;
	}

	n.next->prev = nullptr;
	return n.next;
}

void printList(Node* pNode)
{
	while (pNode)
	{
		cout << pNode->val << "->";
		pNode = pNode->next;
	}

	cout << "NULL" << endl;
}

int main()
{
	Node* pList1 = createList({ 1, 2, 3, 4, 5 ,6});
	printList(pList1);
	Node* pList2 = createList({ 7, 8,9,10});
	printList(pList2);
	Node* pList3 = createList({ 11, 12});
	printList(pList3);

	Node* pList4 = pList1;
	pList1->next->next->child = pList2;
	pList2->next->child = pList3;

	Solution s;
	Node* res = s.flatten(pList4);
	cout << "res is : ";
	printList(res);
	


	return 0;
}