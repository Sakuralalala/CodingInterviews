#include<iostream>
#include<vector>
using namespace std;

class SolutionForNumberOf1 {
public:
	//求给定数中二进制1的个数

	//原数与其减一后的值做与操作，有多少个1就做多少次这种操作
	int numberOf1(int num) {
		int count = 0;
		while (num!=0)
		{
			count++;
			num = num & (num - 1);
		}
		return count;
	}
};
int main() {
	SolutionForNumberOf1 solution;
	cout << solution.numberOf1(16) << endl;
	getchar();
}