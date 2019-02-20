#include<iostream>
#include<vector>
using namespace std;
//输入前序序列以及中序序列，输出重建的二叉树
//1.前序序列中找到根节点，再在中序序列中找到根节点
//2.中序序列中根节点前面的为左子树序列，后面为右子树序列
//找出前序与中序的左右子树
//3.递归
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

	//前序遍历
	static void PreOrder(TreeNode* tree) {
		if (tree == NULL)
			return;
		cout << tree->val << ends;
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
	//中序遍历
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

		//前序遍历第一个节点为根节点
		int rootValue = preV[0];
		TreeNode* root = new TreeNode(preV[0]);
		//在中序遍历中找到根节点的位置
		int rootIndex = 0;
		for (rootIndex; rootIndex < inV.size(); rootIndex++) {
			if (inV[rootIndex] == rootValue)
				break;
		}
		if (rootIndex >= inV.size()) {
			cout << "can't find root";
			return NULL;
		}
		//左右子树的前序与中序序列
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