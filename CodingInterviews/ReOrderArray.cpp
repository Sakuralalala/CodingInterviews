#include<iostream>
#include<vector>
using namespace std;

//使奇数位于数组前面偶数位于数组后面，位置相对不变
class SolutionForReOrderArray {
public:
	void ReOrderArray(vector<int> &array) {
		vector<int> res;
		for (int i = 0; i < array.size(); i++) {
			if (array[i] % 2 == 1)
				res.push_back(array[i]);
		}
		for (int i = 0; i < array.size(); i++) {
			if (array[i] % 2 == 0)
				res.push_back(array[i]);
		}
		array = res;
	}
};

//int main() {
//	SolutionForReOrderArray solution;
//	int array[] = { 1,2,3,4,5,6,7,8,9 };
//	vector<int> orderArray(array, array + 9);
//	for (int i = 0; i < 9; i++) {
//		cout << array[i] << ends;
//	}
//	solution.ReOrderArray(orderArray);
//	for (int i = 0; i < 9; i++) {
//		cout << orderArray[i] << ends;
//	}
//	getchar();
//}