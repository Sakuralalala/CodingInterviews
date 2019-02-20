#include<iostream>
#include<vector>
#include<stack>
#include<cassert>
using namespace std;
//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
//用两个栈
class Solution {
public:
	stack<int> dataStack;
	stack<int> minStack;
	void Push(int value) {
		this->dataStack.push(value);
		if (this->minStack.size() == 0 || value < this->minStack.top())
			this->minStack.push(value);
		else
			this->minStack.push(this->minStack.top());

	}
	void Pop() {
		//设置抛出异常
		assert(this->dataStack.size() > 0 && this->minStack.size() > 0);
		this->dataStack.pop();
		this->minStack.pop();
	}
	int top() {
		assert(this->dataStack.size() > 0 && this->minStack.size() > 0);
		return this->dataStack.top();

	}
	int min() {
		if (this->dataStack.empty())
			return 0;
		return this->minStack.top();
	}

};
//int main() {
//	Solution solution;
//	solution.Push(4);
//	solution.Push(2);
//	solution.Push(3);
//	cout << solution.min() << endl;
//	getchar();
//}