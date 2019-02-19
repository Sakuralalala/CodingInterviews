#include<iostream>
#include<vector>
using namespace std;
//���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������

struct ListNode
{
public:
	int val;
	struct ListNode* next;
};

class Solution {
public:
	ListNode * Merge(ListNode* pLeft,ListNode* pRight) {
		//������
		ListNode* head = NULL;
		ListNode* left = pLeft;
		ListNode* right = pRight;

		if (left == NULL && right != NULL)
			return right;
		if (left != NULL && right == NULL)
			return left;
		if (left == NULL && right == NULL)
			return NULL;

		//ע����Ҫ����ͷ�ڵ�
		//������ͷ�ڵ�!!
		if (left->val < right->val) {
			head = left;
			left = left->next;
		}
		else {
			head = right;
			right = right->next;
		}
		//ָ��ͷ�ڵ��ָ�����ڱ�������Ϊ����ͷ�����ƶ������ص�����headΪͷ�ڵ������
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
	//�ݹ�ʵ��
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