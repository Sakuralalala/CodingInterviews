#include<iostream>
#include<vector>
//��1��N������1���ֵĴ���
using namespace std;
//��132Ϊ����
//��current=3�����ǵ�Ϊʮλ��ʱ��
//ʮλ�Ͽ��ܳ��ֵ�1�ĸ��� = 10~19 +110~119һ��20��( (3��ǰ��һλ1+1)*��ǰλ��(10 = 20;(before+1)*i;
//��102Ϊ����
//current = 0
//ʮλ�Ͽ��ܳ��ֵ�1�ĸ��� = 10~19  = 10����(1*10 = 10;(before*i
//��112Ϊ����
//current = 1
//ʮλ�Ͽ��ܳ��ֵ�1�ĸ��� = 10~19 + 110~112 = 13��( before*i + after +1 
class Solution {
public:
	int NumberOf1Betweeb1AndN(int n) {
		long count = 0;
		long i = 1;
		long current = 0, after = 0, before = 0;
		while ((n / i) != 0)
		{
			//��λ����
			before = n / (i * 10);
			//��ǰλ����
			current = (n / i) % 10;
			//��λ����
			after = n - (n / i)*i;
			if (current > 1) {
				count = count + (before + 1)*i;
			}
			else if (current == 0) {
				count = count + before * i;
			}
			else if (current == 1) {
				count = count + before * i + after + 1;
			}
			i = i * 10;
		}
		return count;
	}
};
//int main() {
//	Solution solution;
//	cout << solution.NumberOf1Betweeb1AndN(11) << ends;
//	getchar();
//}