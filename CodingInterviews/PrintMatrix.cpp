#include<iostream>
#include<vector>
using namespace std;
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
//要点注意边界判断！
class Solution {
public:
	vector<int> PrintMatrix(vector<vector<int> > matrix) {
		vector<int> result;
		if (matrix.empty()) {
			return result;
		}
		//行列最大值
		int rows = matrix.size();
		int cols = matrix[0].size();

		int left = 0;
		int right = cols - 1;
		int top = 0;
		int btm = rows - 1;

		while (left<=right && top<=btm)
		{
			//从左到右
			for (int i = left; i <= right; i++) {
				result.push_back(matrix[top][i]);
			}
			//从上到下
			if (top<btm) {
				for (int i = top+1; i <= btm; i++) {
					result.push_back(matrix[i][right]);
				}
			}
			//从右到左
			if (left < right && top < btm) {
				for (int i = right - 1; i >= left; i--) {
					result.push_back(matrix[btm][i]);
				}
			}
			//从下到上
			if (left < right && top + 1 < btm) {
				for (int i = btm - 1; i >= top+1 ; i--) {
					result.push_back(matrix[i][left]);
				}
			}
			++top;
			++left;
			--right;
			--btm;
		}
		return result;
	}
};
//int main() {
//	int a1[] = { 1,2,3,4 };
//	int a2[] = { 5,6,7,8 };
//	int a3[] = { 9,10,11,12 };
//	int a4[] = { 13,14,15,16 };
//
//	vector<int> vec1(a1, a1 + 4);
//	vector<int> vec2(a2, a2 + 4);
//	vector<int> vec3(a3, a3 + 4);
//	vector<int> vec4(a4, a4 + 4);
//
//	vector<vector<int> > matrix;
//	matrix.push_back(vec1);
//	matrix.push_back(vec2);
//	matrix.push_back(vec3);
//	matrix.push_back(vec4);
//
//	Solution solution;
//	vector<int> result;
//	result= solution.PrintMatrix(matrix);
//
//	for (int i = 0; i < result.size(); i++) {
//		cout << result[i] << ends;
//	}
//	getchar();
//}