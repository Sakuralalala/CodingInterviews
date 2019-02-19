#include<iostream>
#include<vector>
using namespace std;
//输入两颗二叉树A，B，判断B是不是A的子结构。
//第一步，判断父树中有没有节点R与子树的根节点相等
//第二步，判断父树以R为根节点的子树与给定子树是否相等

struct TreeNode
{
public:
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

class Solution {
public:
	bool HasSubtree(TreeNode* parentTree,TreeNode* childTree) {
		if (childTree == NULL ||parentTree == NULL)
			return false;
		bool result = false;

		if (parentTree->val == childTree->val) {
			result = DoseParentHaveChild(parentTree, childTree);
		}

		if (result != true) {
			return (HasSubtree(parentTree->left, childTree) || HasSubtree(parentTree->right, childTree));
		}
		else {
			return true;
		}

	}
	bool DoseParentHaveChild(TreeNode* parentTree, TreeNode* childTree) {
		if (childTree == NULL) {
			return true;
		}
		else if (parentTree == NULL) {
			return false;
		}

		if (parentTree->val != childTree->val) {
			return false;
		}
		else {
			return (DoseParentHaveChild(parentTree->left, childTree->left) && DoseParentHaveChild(parentTree->right, childTree->right));
		}
	}
};
//int main() {
//	TreeNode tree1[5];
//	tree1[0].val = 1;
//	tree1[0].left = &tree1[1];
//	tree1[0].right = &tree1[2];
//	tree1[1].val = 2;
//	tree1[1].left = &tree1[3];
//	tree1[1].right = &tree1[4];
//	tree1[2].val = 3;
//	tree1[2].left = NULL;
//	tree1[2].right = NULL;
//	tree1[3].val = 4;
//	tree1[3].left = NULL;
//	tree1[3].right = NULL;
//	tree1[4].val = 5;
//	tree1[4].left = NULL;
//	tree1[4].right = NULL;
//
//	TreeNode tree2[3];
//	tree2[0].val = 2;
//	tree2[0].left = &tree2[1];
//	tree2[0].right = &tree2[2];
//	tree2[1].val = 4;
//	tree2[1].left = NULL;
//	tree2[1].right = NULL;
//	tree2[2].val = 5;
//	tree2[2].left = NULL;
//	tree2[2].right = NULL;
//
//	Solution solution;
//	cout << solution.HasSubtree(tree1, tree2) << ends;
//	getchar();
//}