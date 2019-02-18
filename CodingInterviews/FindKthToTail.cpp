#include<iostream>
#include<vector>
#include<list>
using namespace std;

struct ListNode {
public:
	int val;
	struct ListNode* next;
};
//������ĵ�����K���ڵ�
//������ָ�룬һ�����ƶ�K���ڵ㣬Ȼ������һ���ƶ�,ֱ����һ��ָ��ָ���
class SolutionForFindKthToTail {
public:
	ListNode * FindKthToTail(ListNode* head,int k) {
		ListNode* right = head;
		ListNode* left = head;
		int i = 0;
		
		if (head == NULL)
			return NULL;
		
		//��ָ�����ƶ�k���ڵ㣬�Ҳ���Ϊ��
		while (i < k && right != NULL) {
			right = right->next;
			i++;
		}
		if (i < k && right == NULL) {
			cout << "error" << ends;
		}
		while (right != NULL)
		{
			right = right->next;
			left = left->next;
		}
		return left;
	}
};

//int main() {
//	ListNode list[5];
//	list[0].val = 1;
//	list[0].next = &list[1];
//	list[1].val = 2;
//	list[1].next = &list[2];
//	list[2].val = 3;
//	list[2].next = &list[3];
//	list[3].val = 4;
//	list[3].next = &list[4];
//	list[4].val = 5;
//	list[4].next = NULL;
//
//	ListNode* node = list;
//	while (node != NULL) {
//		cout << node->val << ends;
//		node = node->next;
//	}
//	SolutionForFindKthToTail solution;
//	cout << solution.FindKthToTail(list, 3)->val << endl;
//	getchar();
//}