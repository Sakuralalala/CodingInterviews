#include<iostream>
#include<vector>
//从1到N整数中1出现的次数
using namespace std;
//以132为例子
//当current=3，就是当为十位的时候
//十位上可能出现的1的个数 = 10~19 +110~119一共20个( (3的前面一位1+1)*当前位数(10 = 20;(before+1)*i;
//以102为例子
//current = 0
//十位上可能出现的1的个数 = 10~19  = 10个，(1*10 = 10;(before*i
//以112为例子
//current = 1
//十位上可能出现的1的个数 = 10~19 + 110~112 = 13个( before*i + after +1 
class Solution {
public:
	int NumberOf1Betweeb1AndN(int n) {
		long count = 0;
		long i = 1;
		long current = 0, after = 0, before = 0;
		while ((n / i) != 0)
		{
			//高位数字
			before = n / (i * 10);
			//当前位数字
			current = (n / i) % 10;
			//低位数字
			after = n - (n / i)*i;
			if (current > 1) {
				count = count + (before + 1)*i;
			}
			else if (current == 0) {
				count = count + before * i;
			}
			else if (current == 1) {
				count = count + before * i + after + 1;
			}
			i = i * 10;
		}
		return count;
	}
};
//int main() {
//	Solution solution;
//	cout << solution.NumberOf1Betweeb1AndN(11) << ends;
//	getchar();
//}