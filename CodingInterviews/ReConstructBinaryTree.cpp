#include<iostream>
#include<vector>
using namespace std;
//����ǰ�������Լ��������У�����ؽ��Ķ�����
//1.ǰ���������ҵ����ڵ㣬���������������ҵ����ڵ�
//2.���������и��ڵ�ǰ���Ϊ���������У�����Ϊ����������
//�ҳ�ǰ�����������������
//3.�ݹ�
struct TreeNode
{
public:
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

	TreeNode(int x)
		: val(x), left(NULL), right(NULL)
	{
	}

	//ǰ�����
	static void PreOrder(TreeNode* tree) {
		if (tree == NULL)
			return;
		cout << tree->val << ends;
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
	//�������
	static void InOrder(TreeNode* tree) {
		if (tree == NULL)
			return;
		InOrder(tree->left);
		cout << tree->val << ends;
		InOrder(tree->right);
	}
};

class Solution {
public:
	TreeNode * ReConstructBinaryTree(vector<int> preV, vector<int> inV) {
		if (preV.size() == NULL || inV.size() == NULL)
			return NULL;
		if (preV.size() != inV.size())
			return NULL;

		//ǰ�������һ���ڵ�Ϊ���ڵ�
		int rootValue = preV[0];
		TreeNode* root = new TreeNode(preV[0]);
		//������������ҵ����ڵ��λ��
		int rootIndex = 0;
		for (rootIndex; rootIndex < inV.size(); rootIndex++) {
			if (inV[rootIndex] == rootValue)
				break;
		}
		if (rootIndex >= inV.size()) {
			cout << "can't find root";
			return NULL;
		}
		//����������ǰ������������
		vector<int> leftPre(rootIndex); vector<int> leftIn(rootIndex);
		vector<int> rightPre(preV.size() - 1 - rootIndex);
		vector<int> rightIn(preV.size() - 1 - rootIndex);

		for (int i = 0; i < preV.size(); i++) {
			if (i < rootIndex) {
				leftPre[i] = preV[i + 1];
				leftIn[i] = inV[i];
			}
			else if(i>rootIndex) {
				rightPre[i - rootIndex - 1] = preV[i];
				rightIn[i - rootIndex - 1] = inV[i];
			}
		}

		root->left = ReConstructBinaryTree(leftPre, leftIn);
		root->right = ReConstructBinaryTree(rightPre, rightIn);
		return root;
	}
};
//int main() {
//	Solution solution;
//	int pre[] = { 1,2,4,7,3,5,6,8 };
//	int in[] = { 4,7,2,1,5,3,8,6 };
//	vector<int> preV(pre, pre + 8);
//	vector<int> inV(in, in + 8);
//	TreeNode* tree = solution.ReConstructBinaryTree(preV, inV);
//	TreeNode::PreOrder(tree);
//	getchar();
//}