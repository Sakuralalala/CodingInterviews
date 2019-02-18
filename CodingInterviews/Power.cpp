#include<iostream>
#include<vector>
using namespace std;

//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//指数通过位运算，和1进行与操作，如果结果为1，则累乘到结果之中，然后指数右移一位
class SolutionForPower {
public:
	//判断函数
	double Power(double base, int exponent) {
		if (exponent == 0)
			return 1.0;
		if (Equal(base, 0.0) == true && exponent < 0) {
			cout << "error" << endl;
			return 0.0;
		}
			
		double res = 1.0;
		if (exponent > 0) {
			res = PowerNormal(base, exponent);
		}
		else {
			res = PowerNormal(base, -exponent);
			res = 1 / res;
		}
		return res;
	}
private:
	//负责计算的函数
	double PowerNormal(double base, int exponent) {
		double res = 1.0;
		double temp = base;
		while (exponent != 0) {
			if ((exponent & 1) == 1) {
				res = res * temp;
			}
			temp *= temp;
			exponent >>= 1;
		}
		return res;
	}
	//用于比较是否等于0
	bool Equal(double left, double right) {
		if (fabs(left - right) <  0.0000001)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
//int main() {
//	SolutionForPower solution;
//	cout << solution.Power(10.0, -2) << endl;
//	getchar();
//}