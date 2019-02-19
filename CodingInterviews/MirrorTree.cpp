#include<iostream>
#include<vector>
using namespace std;
//ÊäÈëÒ»¿Å¶þ²æÊ÷£¬Êä³öÆä¾µÏñ
//½»»»×óÓÒ×ÓÊ÷

struct TreeNode{
public:
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

class Solution {
public:
	TreeNode * MirrorTree(TreeNode* tree) {
		if (tree == NULL)
			return NULL;
		Swap(tree->left, tree->right);
		//swap(tree->left, tree->right);
		MirrorTree(tree->left);
		MirrorTree(tree->right);
		
	}
	void Print(TreeNode* tree) {
		if (tree != NULL)
			cout << tree->val << ends;
		if (tree == NULL)
			return;
		Print(tree->left);
		Print(tree->right);
	}
private:
	void Swap(TreeNode* &left, TreeNode* &right) {
		TreeNode* temp;
		temp = left;
		left = right;
		right = temp;
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
//	Solution solution;
//	solution.Print(tree1);
//	solution.MirrorTree(tree1);
//	solution.Print(tree1);
//	getchar();
//}