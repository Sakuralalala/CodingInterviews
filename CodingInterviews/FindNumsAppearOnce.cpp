#include<iostream>
#include<vector>
using namespace std;
//������ֻ����һ�ε�����
class Solution {
public :
	vector<int> FindNumsAppearOnce(vector<int> num) {
		vector<int> thenum;
		int temp = 0;
		//����ÿλ����ֵ
		for (int i = 0; i < num.size(); i++) {
			temp ^= num[i];
		}
		//cout << temp << ends;
		//���ҽ���е�һλ1��λ��
		int n = 0;
		int index = Find1InBit(temp);
		cout << index << ends;
		int temp1 = 0; int temp2 = 0;
		for (int i = 0; i < num.size(); i++) {
			if (IsBit1(num[i], index))
				temp1 ^= num[i];
			else
				temp2 ^= num[i];
		}
		thenum.push_back(temp1);
		thenum.push_back(temp2);
		return thenum;
	}
	int Find1InBit(int result) {
		int count = 0;
		//ע������
		while ((result & 1) != 1)
		{
			result = result >> 1;
			count++;
		}
		return count;
	}
	bool IsBit1(int num, int index) {
		num = num >> index;
		return (num & 1 == 1);
	}
};
int main() {
	int a[] = { 2,4,3,6,3,2,5,5 };
	vector<int> num(a, a + 8);
	Solution solution;
	vector<int> result = solution.FindNumsAppearOnce(num);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ends;
	}
	getchar();
}