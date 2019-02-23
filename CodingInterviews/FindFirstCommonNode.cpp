#include<iostream>
#include<vector>
using namespace std;
//�������������ҳ����ǵĵ�һ��������㡣
struct ListNode {
public :
	int val;
	struct ListNode *next;
};

class Solution {
public:
	//�����ⷨ������
	ListNode * FindFirstCommonNode(ListNode *firstHead, ListNode *secondHead) {
		ListNode *first = NULL;
		ListNode *second = NULL;
		for (first = firstHead; first!= NULL; first = first->next) {
			for (second = secondHead; second!= NULL; second = second->next) {
				if (first == second) {
					break;
				}
			}
			//ע��break��λ�ò�Ҫ�����!
			if (first == second)
				break;
		}
		return first;
	}
	//�ȶ�������Ȼ��ͬ���ƶ�
	ListNode* FindFirstCommonNode2(ListNode *firstHead, ListNode *secondHead) {
		int firstLength = GetListLength(firstHead);
		int secondLength = GetListLength(secondHead);
		if (firstLength > secondLength) {
			int length = firstLength - secondLength;
			while (firstHead != NULL && length>0)
			{
				firstHead = firstHead->next;
				length--;
			}
		}
		else if(firstLength < secondLength) {
			int length = secondLength - firstLength;
			while (secondHead != NULL && length>0)
			{
				secondHead = secondHead->next;
				length--;
			}
		}
		else {
			while (firstHead != NULL && secondHead != NULL)
			{
				if (firstHead == secondHead) {
					break;
				}
				else {
					firstHead = firstHead->next;
					secondHead = secondHead->next;
				}
			}
		}
		return ((firstHead == secondHead) ? firstHead : NULL);
	}
	//�õ�������
	int GetListLength(ListNode *head) {
		if (head == NULL)
			return 0;
		int count = 0;
		while (head != NULL)
		{
			count++;
			head = head->next;
		}
		return count;
	}
};
int main() {
	ListNode common[2];
	common[0].val = 6;
	common[0].next = &common[1];
	common[1].val = 7;
	common[1].next = NULL;

	ListNode left[3];
	left[0].val = 1;
	left[0].next = &left[1];
	left[1].val = 2;
	left[1].next = &left[2];
	left[2].val = 3;
	left[2].next = &common[0];

	ListNode right[2];
	right[0].val = 4;
	right[0].next = &right[1];
	right[1].val = 5;
	right[1].next = &common[0];
	Solution solution;
	cout << solution.FindFirstCommonNode2(left, right)->val << ends;
	getchar();

}