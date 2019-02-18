#include<iostream>
#include<vector>
#include "minNumberInRotateArray.cpp"
using namespace std;

int main() {
	
	int a[] = { 5,4,3,1,2 };
	vector<int> vec(a, a + 5);
	SolutionForRotateArray solution1;
	cout << solution1.minNumberInRotateArray(vec) << endl;
	
	return 0;
}