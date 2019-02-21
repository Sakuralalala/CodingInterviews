#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//利用全排列算法递归实现
//打印从1到第N位所有的数
class SolutionForMaxOfDigits {
public:
	void PrintToMaxOfNDigits(int n) {
		if (n <= 0)
			return;
		char* number = new char[n + 1];
		number[n] = '\0';

		//从0到9
		for (int i = 0; i < 10; i++) {
			number[0] = i + '0';
			PrintToMaxOfNDigitsRecursively(number, n, 0);
		}
		delete[] number;
	}
	void PrintToMaxOfNDigitsRecursively(char *number, int length, int index) {
		
		if (index == length - 1) {
			PrintNumber(number);
			return;
		}
		for (int i = 0; i < 10; i++) {
			number[index + 1] = i + '0';
			PrintToMaxOfNDigitsRecursively(number, length, index + 1);
		}
		
	}
	void PrintNumber(char* number) {
		int i = 0;
		int length = strlen(number);
		for (i;i<length; i++) {
			if (number[i] != '\0')
				break;
		}
		if(i != length)
			cout << &number[i] << ends;
	}
};

//int main() {
//	SolutionForMaxOfDigits solution;
//	solution.PrintToMaxOfNDigits(2);
//	
//	getchar();
//}