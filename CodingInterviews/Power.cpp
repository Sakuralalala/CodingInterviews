#include<iostream>
#include<vector>
using namespace std;

//����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
//ָ��ͨ��λ���㣬��1�����������������Ϊ1�����۳˵����֮�У�Ȼ��ָ������һλ
class SolutionForPower {
public:
	//�жϺ���
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
	//�������ĺ���
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
	//���ڱȽ��Ƿ����0
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