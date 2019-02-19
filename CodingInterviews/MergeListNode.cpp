#include<iostream>
#include<vector>
using namespace std;
//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则

struct ListNode
{
public:
	int val;
	struct ListNode* next;
};

class Solution {
public:
	ListNode * Merge(ListNode* pLeft,ListNode* pRight) {
		//新链表
		ListNode* head = NULL;
		ListNode* left = pLeft;
		ListNode* right = pRight;

		if (left == NULL && right != NULL)
			return right;
		if (left != NULL && right == NULL)
			return left;
		if (left == NULL && right == NULL)
			return NULL;

		//注意先要生成头节点
		//先生成头节点!!
		if (left->val < right->val) {
			head = left;
			left = left->next;
		}
		else {
			head = right;
			right = right->next;
		}
		//指向头节点的指针用于遍历，因为链表头不能移动，返回的是以head为头节点的链表
		ListNode* pNew = head;
		while (left != NULL && right != NULL) {
			if (left->val < right->val) {
				pNew->next = left;
				pNew = pNew->next;
				left = left->next;
			}
			else
			{
				pNew->next = right;
				pNew = pNew->next;
				right = right->next;
			}
		}

		if (left != NULL) {
			pNew->next = left;
		}
		else {
			pNew->next = right;
		}
		return head;
	}
	//递归实现
	ListNode* Merge2(ListNode* pLeft, ListNode* pRight) {
		if (pLeft == NULL)
			return pRight;
		if (pRight == NULL)
			return pLeft;

		ListNode* head = NULL;
		if (pLeft->val < pRight->val) {
			head = pLeft;
			head->next = Merge2(pLeft->next,pRight);
		}
		else {
			head = pRight;
			head->next = Merge2(pLeft, pRight->next);
		}
		return head;
	}
};
//int main() {
//	ListNode listLeft[3];
//	ListNode listRight[2];
//
//	listLeft[0].val = 1;
//	listLeft[0].next = &listLeft[1];
//	listLeft[1].val = 3;
//	listLeft[1].next = &listLeft[2];
//	listLeft[2].val = 5;
//	listLeft[2].next = NULL;
//
//	listRight[0].val = 2;
//	listRight[0].next = &listRight[1];
//	listRight[1].val = 4;
//	listRight[1].next = NULL;
//
//	Solution solution;
//	ListNode* current = solution.Merge2(listLeft, listRight);
//	
//	while (current != NULL) {
//		cout << current->val << endl;
//		current = current->next;
//	}
//	getchar();
//}