#include<iostream>
#include<vector>
using namespace std;
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == NULL)
			return false;
		return Verify(sequence, 0, sequence.size() - 1);
	}

	bool Verify(vector<int> sequence, int left, int right) {

		if (left >= right)
			return true;

		int mid = right - 1;
		while (sequence[mid] > sequence[right]) {
			mid--;
		}
		
		int i = left;
		while (i<mid && sequence[i] < sequence[right])
		{
			i++;
		}
		
		if (i < mid) {
			return false;
		}

		return Verify(sequence, left, mid) && Verify(sequence, mid + 1, right - 1);
	}
};
//int main() {
//	int a[] = { 2,9,5,16,17,15,19,18,12 };
//	vector<int> sequence(a, a + 9);
//	Solution solution;
//	cout << solution.VerifySquenceOfBST(sequence) << ends;
//	getchar();
//}