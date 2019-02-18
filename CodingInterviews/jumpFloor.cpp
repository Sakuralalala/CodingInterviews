#include<iostream>
#include<vector>
using namespace std;

class SolutionForJumpFloor {
public:
	//斐波拉契数列
	int jumpFloor(int n) {
		if (n <= 2)
			return n;
		long one = 1;
		long two = 2;
		long res = 0;
		for (int i = 3; i <= n; i++) {
			res = one + two;
			one = two;
			two = res;
		}
		return res;
	}
	//变态跳台阶，n个阶梯有n种跳法，1阶，2阶...n阶
	//找到规律！
	//n=0,1
	//n=1,1
	//n>=2,2*f(n-1)
	int jumpFloor2(int n) {
		if (n <= 0)
			return -1;
		if (n == 1)
			return 1;
		else
			return 2 * jumpFloor2(n - 1);

	}
};
//int main() {
//	SolutionForJumpFloor solution;
//	cout << solution.jumpFloor(4) << endl;
//	cout << solution.jumpFloor2(3) << endl;
//	getchar();
//}