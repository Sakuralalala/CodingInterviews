#include<iostream>
#include<vector>
using namespace std;
//判断一个树是否为平衡二叉树
//输出二叉树的深度
struct TreeNode {
public:
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {

	}
};

class Solution {
public:
	int max(int a, int b) {
		if (a >= b)
			return a;
		else
			return b;
	}
	int TreeDepth(TreeNode *root) {
		if (root == NULL)
			return 0;

		int leftDepth = TreeDepth(root->left);
		int rightDepth = TreeDepth(root->right);

		return max(leftDepth, rightDepth) + 1;
	}
	bool IsBalanceTree(TreeNode *root) {
		if (root == NULL)
			return true;

		int leftDepth = TreeDepth(root->left);
		int rightDepth = TreeDepth(root->right);
		
		if (fabs(leftDepth - rightDepth) <= 1) {
			return IsBalanceTree(root->left) && IsBalanceTree(root->right);
		}
		else {
			return false;
		}
	}
};
//int main() {
//	TreeNode *node = new TreeNode(2);
//	TreeNode *node1 = new TreeNode(1);
//	TreeNode *node2 = new TreeNode(3);
//	TreeNode *node3 = new TreeNode(5);
//	TreeNode *node4 = new TreeNode(4);
//	TreeNode *node5 = new TreeNode(6);
//	node->left = node1;
//	node->right = node2;
//	node2->left = node3;
//	node2->right = node4;
//	node4->right = node5;
//
//	Solution solution;
//	cout << solution.TreeDepth(node) << ends;
//	cout << solution.IsBalanceTree(node) << ends;
//	getchar();
//}