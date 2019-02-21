#include<iostream>
#include<vector>
using namespace std;
//查找数组中第K小的元素
//快速排序
class Solution {
public:
	int FindKthNumber(vector<int> &number, int left, int right, int k) {
		int pNum = left +1;
		if (left == right)
			return number[left];
		//查找left所在的数组位置,即是第几大
		pNum = Partition(number, left, right);
		
		if (pNum > k) {
			//pNum > k 说明要找的数在left 到 pNum -1 之间
			return FindKthNumber(number, left, pNum - 1,k);
		}
		else if (pNum < k) {
			return FindKthNumber(number, pNum + 1, right,k);
		}
		else {
			return number[pNum];
		}
	}
	//返回left下标元素在数组中的位置
	//快排的分割函数
	int Partition(vector<int> &number, int left, int right) {
		int i = left; int j = right;
		//选定基准数
		int pNum = number[i];
		while (i<j)
		{
			while (i<j && number[j] >= pNum)
			{
				j--;
			}
			number[i] = number[j];
			while (i<j && number[i] <= pNum)
			{
				i++;
			}
			number[j] = number[i];
		}
		number[i] = pNum;
		return i;
	}
	void FastSort(vector<int> &number, int left, int right) {
		if (left >= right) {
			return;
		}
		int i = left;
		i = Partition(number, left, right);
		FastSort(number, left, i - 1);
		FastSort(number, i + 1, right);
	}
};
//int main() {
//	int a[] = { 5,4,8,3,6,9,1,2 };
//	vector<int> num(a, a + 8);
//	Solution solution;
//	//cout << solution.FindKthNumber(num, 0, num.size() - 1, 0) << ends;
//	solution.FastSort(num, 0, num.size() - 1);
//	for (int i = 0; i < num.size(); i++) {
//		cout << num[i] << ends;
//	}
//	getchar();
//}