#include<iostream>
#include<vector>
using namespace std;
//寻找数组中出现次数大于一半的值
class Solution {
public:
	int MoreThanHalfNum(vector<int> num) {
		if (num.size() == NULL) {
			return 0;
		}
		if (num.size() == 1) {
			return num[0];
		}
		int pNum = num[0];
		int count = 1;
		for (int i = 0; i < num.size(); i++) {
			if (pNum == num[i]) {
				count++;
			}
			else {
				count--;
			}
			if (count == 0) {
				pNum = num[i];
				count = 1;
			}
		}
		
		if (count > 0) {
			count = 0;
			for (int i = 0; i < num.size(); i++) {
				if (num[i] == pNum)
					count++;
			}
		}
		if (count > num.size() / 2)
			return pNum;
		else
			return 0;
	}
};
int main() {
	int a[] = { 1,6,6,6,8,5,6 };
	vector<int> num(a, a + 7);
	Solution solution;
	cout << solution.MoreThanHalfNum(num) << ends;
	getchar();
}