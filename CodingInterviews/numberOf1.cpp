#include<iostream>
#include<vector>
using namespace std;

class SolutionForNumberOf1 {
public:
	//��������ж�����1�ĸ���

	//ԭ�������һ���ֵ����������ж��ٸ�1�������ٴ����ֲ���
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