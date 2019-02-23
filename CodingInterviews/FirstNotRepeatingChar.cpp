#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	//暴力解法
	//易错点：当前后两个字母相同时(abbca)注意bb时，将第二个b置为空否则将会重复遍历造成错误
	int FirstNotRepeatingChar(string str) {
		if (str.size() == 0)
			return -1;
		bool isNotRepating = true;
		for (int i = 0; i < str.size(); i++) {
			isNotRepating = true;
			if (str[i] == '\0')
				continue;
			for (int j = i + 1; j < str.size(); j++) {
				if (str[j] == '\0') {
					continue;
				}
				else if (str[i] == str[j]) {
					isNotRepating = false;
					str[j] = '\0';
				}
				
			}
			if (isNotRepating == true) {
				return i;
			}
		}
		return -1;
	}
	//计数法
	int count[256];
	int FirstNotRepeatingChar2(string str) {
		if (str.size() == 0)
			return -1;
		//注意将数组清零
		memset(count, '\0', sizeof(count));
		for (int i = 0; i < str.size(); i++) {
			count[(int)str[i]]++;
		}
		for (int i = 0; i < str.size(); i++) {
			if (count[(int)str[i]] == 1)
				return i;
		}
		return -1;
	}
};
//int main() {
//	string s = "abbca";
//	Solution solution;
//	cout << solution.FirstNotRepeatingChar2(s) << ends;
//	getchar();
//}