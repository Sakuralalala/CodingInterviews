#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
//�������ų���С����
template<class T>
string ToString(const T& t) {
	ostringstream oss;//����һ����
	oss << t;//��ֵ����������
	return oss.str();//��ȡת������ַ�ת������д��result
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
		//����������ת��Ϊ�ַ�������
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