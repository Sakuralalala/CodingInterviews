#include<iostream>
#include<vector>
#include<deque>
using namespace std;
//从上到下打印二叉树
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
	vector<int> res;

public:
	vector<int> PrintFromTopToBtm(TreeNode* root) {

		//LevelOrder(root);
		//LevelOrderDeque(root);
		LevelOrder2(root);
		return this->res;
	}

	//打印某一层的节点
	int PrintOrder(TreeNode* root,int level) {
		if (root == NULL)
			return 0;
		if (level == 0) {
			res.push_back(root->val);
			return 1;
		}
		else {
			return PrintOrder(root->left, level - 1) + PrintOrder(root->right, level - 1);
		}
	}
	//用递归的方式打印每一层
	void LevelOrder(TreeNode* root) {
		res.clear();
		if (root == NULL)
			return;
		for (int level = 0;; level++) {
			if (PrintOrder(root, level) == 0)
				break;
		}
	}
	//用两个双端队列
	void LevelOrderDeque(TreeNode* root) {
		res.clear();
		deque<TreeNode*> first, second;
		first.push_back(root);
		while (first.size() != NULL)
		{
			while (first.size() != NULL)
			{
				TreeNode* temp = first.front();
				first.pop_front();
				res.push_back(temp->val);

				if (temp->left != NULL) {
					second.push_back(temp->left);
				}
				if (temp->right != NULL) {
					second.push_back(temp->right);
				}
			}
			first.swap(second);//交换两个队列
		}
	}
	//用两个游标来实现
	void LevelOrder2(TreeNode* root) {
		vector<TreeNode*> vec;
		vec.push_back(root);
		//两个游标
		int cur = 0;
		int end = 1;

		while (cur <vec.size())
		{
			end = vec.size();
			while (cur < end)
			{
				res.push_back(vec[cur]->val);

				if (vec[cur]->left != NULL)
					vec.push_back(vec[cur]->left);
				if (vec[cur]->right != NULL)
					vec.push_back(vec[cur]->right);
				cur++;
			}
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
//	/*vector<TreeNode*> tree;
//	tree.push_back(tree1);
//	cout << tree.size() << endl;*/
//
//	Solution solution;
//	vector<int> vec = solution.PrintFromTopToBtm(tree1);
//	
//	for (int i = 0; i < vec.size(); i++) {
//		cout << vec[i] << ends;
//	}
//	getchar();
//}