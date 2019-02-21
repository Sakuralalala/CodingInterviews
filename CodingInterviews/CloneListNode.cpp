#include<iostream>
#include<vector>
using namespace std;

struct RandomListNode {
public:
	int val;
	struct RandomListNode* next;
	struct RandomListNode* random;

	RandomListNode(int x) :
		val(x), next(NULL), random(NULL) {

	}
};

class Solution {
public:
	//暴力求解
	RandomListNode * Clone(RandomListNode* pHead) {
		if (pHead == NULL)
			return NULL;

		RandomListNode* current = pHead;
		RandomListNode* newHead = NULL;//新链表的头
		RandomListNode* newNode = NULL;//新链表的节点
		RandomListNode* preNode = NULL;//指向前一个节点的指针

		//克隆常规部分
		while (current != NULL)
		{
			newNode = new RandomListNode(current->val);
			current = current->next;
			if (preNode == NULL) {
				//preNode = newNode;
				newHead = newNode;
			}
			else {
				preNode->next = newNode;
			}
			preNode = newNode;
		}
		
		current = pHead;
		newNode = newHead;
		//克隆随机部分
		while (current != NULL && newNode != NULL)
		{
			newNode->random = FindNodeInNew(pHead, newHead, current->random);
			current = current->next;
			newNode = newNode->next;
		}
		return newHead;

	}
	RandomListNode* FindNodeInNew(RandomListNode* pOld, RandomListNode* pNew, RandomListNode* random) {
		RandomListNode* current = pOld;
		RandomListNode* newNode = pNew;
		while (current != NULL && newNode != NULL)
		{
			if (random == current) {
				return newNode;
			}
			current = current->next;
			newNode = newNode->next;
		}
		return NULL;
	}
	//时间空间复杂度更优秀的解法
	RandomListNode* Clone2(RandomListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		RandomListNode* newHead = NULL;
		RandomListNode* newNode = NULL;
		RandomListNode* current = pHead;

		//复制普通部分
		while (current != NULL)
		{
			newNode = new RandomListNode(current->val);
			newNode->next = current->next;
			current->next = newNode;
			current = newNode->next;
		}
		//复制随机部分
		current = pHead;
		newNode = pHead->next;
		while (current != NULL) {

			newNode = current->next;
			if (current->random != NULL) {
				newNode->random = current->random->next;
			}
			else
			{
				newNode->random = NULL;
			}
			current = newNode->next;
			//newNode = current->next;
		}
		//旧链与新链分离
		current = pHead;
		newNode = current->next;//写的时候搞反了这两句的顺序，导致newHead = 前面的newNode了
		newHead = newNode;
		while (current != NULL)
		{
			current->next = newNode->next;
			if (newNode->next != NULL) {
				newNode->next = newNode->next->next;
			}
			else {
				newNode->next = NULL;
			}
			current = current->next;
			newNode = newNode->next;
		}
		return newHead;
	}
	


};
//int main() {
//	Solution solution;
//	RandomListNode* list = new RandomListNode(1);
//	RandomListNode* node1 = new RandomListNode(2);
//	RandomListNode* node2 = new RandomListNode(3);
//	RandomListNode* node3 = new RandomListNode(4);
//	list->next = node1;
//	list->random = node2;
//	node1->next = node2;
//	node1->random = node3;
//	node2->next = node3;
//	node2->random = NULL;
//	node3->next = NULL;
//	node3->random = list;
//	RandomListNode* curr = list;
//
//	/*while (curr != NULL)
//	{
//		cout << curr->val << ends;
//		if (curr->random != NULL)
//			cout << curr->random->val << ends;
//		curr = curr->next;
//	}*/
//	RandomListNode* clone1 = solution.Clone(curr);
//	while (clone1 != NULL)
//	{
//		cout << clone1->val << ends;
//		if (clone1->random != NULL)
//			cout << clone1->random->val << ends;
//		clone1 = clone1->next;
//	}
//	getchar();
//}