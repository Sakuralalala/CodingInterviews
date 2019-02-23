#include<iostream>
#include<vector>
using namespace std;
//找到第N个丑数(因子只含2，3，5)
class Solution {
public:
	bool IsUglyNumber(int number) {

		while (number % 2 == 0) {
			number /= 2;
		}
		while (number % 3 == 0)
		{
			number /= 3;
		}
		while (number % 5 == 0)
		{
			number /= 5;
		}
		return(number == 1);
	}
	int GetUglyNumber(int N) {
		if (N <= 0) {
			return -1;
		}
		int count = 1;
		int number = 0;
		while (count <= N)
		{
			number++;
			if (IsUglyNumber(number) == true) {
				count++;
			}
		}
		return number;
	}

	int GetUglyNumber2(int N) {
		if (N <= 0)
			return -1;
		int index2 = 0;
		int index3 = 0;
		int index5 = 0;
		int index = 1;
		ugly[0] = 1;
		while (index < N)
		{
			int val = min(ugly[index2] * 2, ugly[index3] * 3, ugly[index5] * 5);
			if (val == ugly[index2] * 2) {
				++index2;
			}
			if (val == ugly[index3] * 3) {
				++index3;
			}
			if (val == ugly[index5] * 5) {
				++index5;
			}
			ugly[index++] = val;
		}
		return ugly[N - 1];
	}


private:
	int ugly[1000];
	int min(int a, int b, int c) {
		int temp = (a < b) ? a : b;
		return ((temp < c) ? temp : c);
	}

};

//int main() {
//	Solution solution;
//	cout << solution.GetUglyNumber2(4) << ends;
//	getchar();
//}