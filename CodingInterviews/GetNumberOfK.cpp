#include<iostream>
#include<vector>
using namespace std;
//ͳ��һ�����������������г��ֵĴ���
class Solution {
public:
	//�������
	int GetNumberOfK(vector<int> data, int k) {
		int count = 0;
		if (data.size() == 0)
			return 0;
		for (int i = 0; i < data.size() && data[i]<=k; i++) {
			if (data[i] == k) {
				count++;
			}
		}
		return count;
	}
	//����������,���ҵ������֣�Ȼ����ǰ�ȶԣ����ȶ�
	int GetNumberOfK2(vector<int> data, int k) {
		
		if (data.size() == 0)
			return 0;
		int count = 1;
		int pNum = BinarySearch(data, 0, data.size() - 1, k);
		if (pNum < 0) {
			return -1;
		}
		//����ȶ�
		for (int i = pNum - 1; i >= 0 && data[i] == k; i--) {
			count++;//ϸ�ڳ���,i>=0!
		}
		//���ұȶ�
		for (int i = pNum + 1; i < data.size() && data[i] == k; i++) {
			count++;
		}
		return count;
	}
	int BinarySearch(vector<int> data, int left ,int right,int k) {
		if (data.size() == 0)
			return 0;
		int i = left;
		int j = right;
		int mid = (left + right) / 2;
		if (data[mid] < k) {
			return BinarySearch(data, mid + 1, right, k);
		}
		else if (data[mid] > k) {
			return BinarySearch(data, 0, mid - 1, k);
		}
		else {
			return mid;
		}
		return -1;
	}

};
//int main() {
//	int a[] = { 1,2,2,3,4,5 };
//	vector<int> data(a, a + 6);
//	Solution solution;
//	cout << solution.GetNumberOfK2(data,2) << ends;
//	getchar();
//}