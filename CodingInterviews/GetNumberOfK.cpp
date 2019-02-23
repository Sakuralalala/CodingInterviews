#include<iostream>
#include<vector>
using namespace std;
//统计一个数字在排序数组中出现的次数
class Solution {
public:
	//暴力求解
	int GetNumberOfK(vector<int> data, int k) {
		int count = 0;
		if (data.size() == 0)
			return 0;
		for (int i = 0; i < data.size() && data[i]<=k; i++) {
			if (data[i] == k) {
				count++;
			}
		}
		return count;
	}
	//二分搜索法,先找到该数字，然后向前比对，向后比对
	int GetNumberOfK2(vector<int> data, int k) {
		
		if (data.size() == 0)
			return 0;
		int count = 1;
		int pNum = BinarySearch(data, 0, data.size() - 1, k);
		if (pNum < 0) {
			return -1;
		}
		//向左比对
		for (int i = pNum - 1; i >= 0 && data[i] == k; i--) {
			count++;//细节出错,i>=0!
		}
		//向右比对
		for (int i = pNum + 1; i < data.size() && data[i] == k; i++) {
			count++;
		}
		return count;
	}
	int BinarySearch(vector<int> data, int left ,int right,int k) {
		if (data.size() == 0)
			return 0;
		int i = left;
		int j = right;
		int mid = (left + right) / 2;
		if (data[mid] < k) {
			return BinarySearch(data, mid + 1, right, k);
		}
		else if (data[mid] > k) {
			return BinarySearch(data, 0, mid - 1, k);
		}
		else {
			return mid;
		}
		return -1;
	}

};
//int main() {
//	int a[] = { 1,2,2,3,4,5 };
//	vector<int> data(a, a + 6);
//	Solution solution;
//	cout << solution.GetNumberOfK2(data,2) << ends;
//	getchar();
//}