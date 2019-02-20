#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		if (pushV.size() != popV.size() || pushV.size() == 0 || popV.size() == 0)
			return false;
		int pop = 0;
		int push = 0;
		s.push(pushV[0]);
		for (pop, push; pop < popV.size() && push < pushV.size();) {
			if (s.empty()!=true && s.top() == popV[pop]) {
				s.pop();
				pop++;
			}
			else {
				++push;
				//��ֹvectorԽ��
				if (push < pushV.size()) {
					s.push(pushV[push]);
				}
			}
			
		}
		if (s.empty() == true)
			return true;
		else
			return false;
	}
};
//int main() {
//	int a1[] = { 1,2,3,4 };
//	int a2[] = { 4,3,2,1 };
//	vector<int> push(a1, a1 + 4);
//	vector<int> pop(a2, a2 + 4);
//	Solution solution;
//	cout << solution.IsPopOrder(push, pop) << endl;
//	getchar();
//}