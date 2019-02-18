#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//����ȫ�����㷨�ݹ�ʵ��
//��ӡ��1����Nλ���е���
class SolutionForMaxOfDigits {
public:
	void PrintToMaxOfNDigits(int n) {
		if (n <= 0)
			return;
		char* number = new char[n + 1];
		number[n] = '\0';

		//��0��9
		for (int i = 0; i < 10; i++) {
			number[0] = i +'0';
			PrintToMaxOfNDigitsRecursively(number, n, 0);
		}
		delete[] number;
	}
	void PrintToMaxOfNDigitsRecursively(char *number, int length, int index) {
		
		if (index == length - 1) {
			PrintNumber(number);
			return;
		}
		//��ǰλ��0��9
		for (int i = 0; i < 10; i++) {
			number[index + 1] = i +'0';
			PrintToMaxOfNDigitsRecursively(number, length, index + 1);
		}
	}
	void PrintNumber(char* number) {
		int i = 0;
		int length = strlen(number);
		
		for (i = 0; i < length; i++) {
			if (number[i] != '0')
				break;
		}
		if (i != length) {
			cout << &number[i] << endl;//ǰ���0�����
		}
		
		
	}
};

//int main() {
//	SolutionForMaxOfDigits solution;
//	solution.PrintToMaxOfNDigits(2);
//	
//	getchar();
//}