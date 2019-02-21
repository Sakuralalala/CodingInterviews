#include<iostream>
#include<vector>
using namespace std;
//���������е�KС��Ԫ��
//��������
class Solution {
public:
	int FindKthNumber(vector<int> &number, int left, int right, int k) {
		int pNum = left +1;
		if (left == right)
			return number[left];
		//����left���ڵ�����λ��,���ǵڼ���
		pNum = Partition(number, left, right);
		
		if (pNum > k) {
			//pNum > k ˵��Ҫ�ҵ�����left �� pNum -1 ֮��
			return FindKthNumber(number, left, pNum - 1,k);
		}
		else if (pNum < k) {
			return FindKthNumber(number, pNum + 1, right,k);
		}
		else {
			return number[pNum];
		}
	}
	//����left�±�Ԫ���������е�λ��
	//���ŵķָ��
	int Partition(vector<int> &number, int left, int right) {
		int i = left; int j = right;
		//ѡ����׼��
		int pNum = number[i];
		while (i<j)
		{
			while (i<j && number[j] >= pNum)
			{
				j--;
			}
			number[i] = number[j];
			while (i<j && number[i] <= pNum)
			{
				i++;
			}
			number[j] = number[i];
		}
		number[i] = pNum;
		return i;
	}
	void FastSort(vector<int> &number, int left, int right) {
		if (left >= right) {
			return;
		}
		int i = left;
		i = Partition(number, left, right);
		FastSort(number, left, i - 1);
		FastSort(number, i + 1, right);
	}
};
//int main() {
//	int a[] = { 5,4,8,3,6,9,1,2 };
//	vector<int> num(a, a + 8);
//	Solution solution;
//	//cout << solution.FindKthNumber(num, 0, num.size() - 1, 0) << ends;
//	solution.FastSort(num, 0, num.size() - 1);
//	for (int i = 0; i < num.size(); i++) {
//		cout << num[i] << ends;
//	}
//	getchar();
//}