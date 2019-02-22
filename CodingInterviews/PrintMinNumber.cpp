#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
//把数组排成最小的数
template<class T>
string ToString(const T& t) {
	ostringstream oss;//创建一个流
	oss << t;//把值传递如流中
	return oss.str();//获取转换后的字符转并将其写入result
}

class Solution {
public:
	static bool Compare(const string &left, const string &right) {
		string leftright = left + right;
		string rightleft = right + left;

		return leftright < rightleft;
	}

	string PrintMinNumber(vector<int> number) {
		string res = "";
		string str;
		vector<string> strNum;
		//将整数类型转换为字符串类型
		for (int i = 0; i < number.size(); i++) {
			str = ToString(number[i]);
			strNum.push_back(str);
		}
		sort(strNum.begin(), strNum.end(), Compare);
		for (int i = 0; i < strNum.size(); i++) {
			res += strNum[i];
		}
		return res;
	}
};
//int main()
//{
//	Solution solu;
//
//	int arr[] = { 321, 32, 3 };
//	vector<int> vec(arr, arr + 3);
//	cout << solu.PrintMinNumber(vec) << endl;
//	getchar();
//}