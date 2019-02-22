#include<iostream>
#include<vector>
//连续子序列的最大和(动态规划)
using namespace std;

class Solution {
	int fi[1000];
public:
	//动态规划要点是把递推公式找到
	int FindGreatestSumOfSubArray(vector<int> vec) {
		int max = INT_MIN;
		if (vec.size() == 0)
			return 0;
		for (int i = 0; i < vec.size(); i++) {
			//cout << "debug" << ends;
			//cout << i << ends;
			if (fi[i - 1] <= 0) {
				fi[i] = vec[i];
			}
			else {
				fi[i] = fi[i - 1] + vec[i];
			}

			if (fi[i] > max)
				max = fi[i];

		}
		return max;
	}
	//贪婪策略
	int FindGreatestSunOfSubArray2(vector<int> vec) {
		int sum;
		int maxSum = INT_MIN;
		if (vec.size() == 0)
			return 0;
		for (int i = 0; i < vec.size(); i++) {
			if (sum <= 0) {
				sum = vec[i];
			}
			else {
				sum += vec[i];
			}
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
		return maxSum;
	}
};
//int main() {
//	int a[] = { 6,-3,-2,7,-15,1,2,2 };
//	vector<int> num(a, a + 8);
//	Solution solution;
//	cout << solution.FindGreatestSumOfSubArray(num) << ends;
//	getchar();
//}