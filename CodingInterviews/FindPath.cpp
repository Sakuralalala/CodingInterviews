#include<iostream>
#include<vector>
using namespace std;
//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	/*TreeNode(int x) :
	val(x), left(NULL), right(NULL) {

	}*/
};
class Solution {
public:
	vector<vector<int> > result;
	vector<vector<int> > FindPath(TreeNode* root,int number) {
		if (root == NULL)
			return result;

		vector<int> path;
		FindPath(root, number, path, 0);
		return result;
	}
	
	void FindPath(TreeNode* root, int number, vector<int> path, int currentNum) {
		currentNum += root->val;
		path.push_back(root->val);

		if (currentNum == number && (root->left == NULL && root->right == NULL)) {
			result.push_back(path);
		}
		if (root->left != NULL)
			FindPath(root->left, number, path, currentNum);
		if (root->right != NULL)
			FindPath(root->right, number, path, currentNum);

	}
};
//int main() {
//	Solution solution;
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
//	vector<vector<int> > res = solution.FindPath(tree1, 7);
//	for (int i = 0; i < res.size(); i++) {
//		for (int j = 0; j < res[i].size(); j++) {
//			cout << res[i][j] << ends;
//		}
//	}
//	getchar();
//}