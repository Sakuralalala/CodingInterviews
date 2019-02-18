#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
public:
	int val;
	struct ListNode* next;
};


class SolutionForReverseList {
public:
	ListNode * ReverseList(ListNode* head) {
		ListNode* pNode = head;
		ListNode* pPrev = NULL;
		ListNode* pNext = NULL;

		//pPrev->pNode->pNext
		while (pNode != NULL)
		{
			pNext = pNode->next;
			pNode->next = pPrev;
			pPrev = pNode;
			pNode = pNext;
		}
		return pPrev;
	}
};
int main() {
	ListNode list[5];
	list[0].val = 1;
	list[0].next = &list[1];
	list[1].val = 2;
	list[1].next = &list[2];
	list[2].val = 3;
	list[2].next = &list[3];
	list[3].val = 4;
	list[3].next = &list[4];
	list[4].val = 5;
	list[4].next = NULL;

	SolutionForReverseList solution;
	ListNode * node = solution.ReverseList(list);
	while (node != NULL) {
		cout << node->val << ends;
		node = node->next;
	}

	getchar();
}