#include<iostream>
#include<vector>
using namespace std;
//找到数组中前k小的数
class Solution {
public:
	vector<int> FindKVector(vector<int> &number, int left, int right, int k) {
		vector<int> res;
		if (number.size() == 0)
			return res;
		int pNum = FindK(number, left, right, k);
		for (int i = 0; i < pNum; i++) {
			res.push_back(number[i]);
		}
		return res;
	}
	int FindK(vector<int> &number, int left, int right, int k) {
		int pNum = 0;
		if (number.size() == 0)
			return 0;
		/*if (left == right)
			return left;*/
		pNum = Partition(number, left, right);
		if (pNum > k) {
			pNum = FindK(number, left, pNum - 1, k);
		}
		else if (pNum < k) {
			pNum = FindK(number, pNum + 1, right, k);
		}
		else {
			return pNum;
		}
	}
	//分割函数
	int Partition(vector<int> &number, int left, int right) {
		if (number.size() == 0)
			return 0;
		int i = left;
		int j = right;
		int pivotNum = number[i];
		while (i<j)
		{
			while (i<j && number[j] >= pivotNum)
			{
				j--;
			}
			number[i] = number[j];
			while (i<j && number[i] <= pivotNum)
			{
				i++;
			}
			number[j] = number[i];
		}
		number[i] = pivotNum;
		return i;
	}
};
//int main() {
//	int a[] = { 5,4,8,3,6,9,1,2 };
//	vector<int> num(a, a + 8);
//	Solution solution;
//	vector<int> res = solution.FindKVector(num, 0, num.size() - 1, 3);
//	for (int i = 0; i < res.size(); i++) {
//		cout << res[i] << ends;
//	}
//	getchar();
//}