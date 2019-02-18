#include<iostream>
#include<vector>
using namespace std;

class SolutionForRotateArray
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) {

		if (rotateArray.size() == 0) 
		{
			cout << "error" << endl;
			return 0;
		}
		int mid = 0;
		int low = 0;
		int high = rotateArray.size() - 1;

		if (rotateArray[low] < rotateArray[high]) {
			cout << "error input" << endl;
		}
		while (rotateArray[low] >= rotateArray[high])
		{
			if ((high - low) == 1) {
				mid = high;
				break;
			}
			mid = (low + high) / 2;

			if (rotateArray[low] == rotateArray[mid] && rotateArray[high] == rotateArray[mid]) {
				minOrder(rotateArray, low, high);
			}

			if (rotateArray[mid] >= rotateArray[low]) {
				low = mid;
			}
		    else if (rotateArray[mid] <= rotateArray[high]) {
				high = mid;
			}
		}
		return rotateArray[mid];
	}
private:
	int minOrder(vector<int> num, int low, int high) {
		int result = num[low];
		for (int i = low + 1; i < high; i++) {
			if (num[i] < result) {
				result = num[i];
			}
		}
		return result;
	}
};
//int main() {
//	int a[] = { 1, 0, 1, 1, 1, };
//	vector<int>vec(a, a + 5);
//	SolutionForRotateArray solution;
//	cout << solution.minNumberInRotateArray(vec) << endl;
//	getchar();
//	return 0;
//}