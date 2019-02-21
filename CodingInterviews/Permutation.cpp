#include<iostream>
#include<vector>
#include<string>
using namespace std;
//�ַ�����ȫ����
class Solution {
public:
	vector<string> res;
	vector<string> Permutation(string str) {
		if (str.empty() == true)
			return res;
		PermutationRecursion(str, 0);
		return res;
	}

	void PermutationRecursion(string str, int begin) {
		if (str[begin] == '\0') {
			res.push_back(str);
			//return;
		}
		else {
			for (int i = begin; str[i] != '\0'; i++) {
				if (!HasDuplicate(str, begin, i)) {
					swap(str[begin], str[i]);
					PermutationRecursion(str, begin + 1);
				}
			}
		}
	}
private:
	//������str[k,i)���Ƿ�����str[i]��ȵ�Ԫ��
	bool HasDuplicate(string str, int k, int i) {
		for (int p = k; p < i; p++) {
			if (str[p] == str[i])
				return true;
		}
		return false;
	}
};
//int main() {
//	string s = "abc";
//	Solution solution;
//	vector<string> res = solution.Permutation(s);
//	for (int i = 0; i < res.size(); i++) {
//		cout << res[i] << ends;
//	}
//	getchar();
//}