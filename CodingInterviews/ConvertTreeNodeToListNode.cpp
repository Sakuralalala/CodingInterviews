#include<iostream>
#include<vector>
using namespace std;
//将二叉搜索树转化为双向链表
struct TreeNode {
public:
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

	/*TreeNode(int x) :
		val(x), left(NULL), right(NULL) {

	}*/
};

class Solution {
public:
	TreeNode* Convert(TreeNode* root) {
		if (root == NULL)
			return NULL;
		TreeNode* pLastNode = NULL;
		ConvcertRecusion(root, &pLastNode);

		//将pLastNode从尾节点返回到头节点
		while (pLastNode != NULL && pLastNode->left != NULL)
		{
			pLastNode = pLastNode->left;
		}
		return pLastNode;
	}

	void ConvcertRecusion(TreeNode* root, TreeNode* *pLastNode) {
		TreeNode *current = root;

		//左
		if (current->left != NULL) {
			ConvcertRecusion(current->left, pLastNode);
		}
		//中
		current->left = *pLastNode;
		if (*pLastNode != NULL) {
			(*pLastNode)->right = current;
		}
		(*pLastNode) = current;
		//右
		if (current->right != NULL) {
			ConvcertRecusion(current->right, pLastNode);
		}
	}
};
//int main() {
//	TreeNode tree[4];
//	tree[0].val = 4;
//	tree[0].left = &tree[1];
//	tree[0].right = &tree[2];
//	tree[1].val = 3;
//	tree[1].left = &tree[3];
//	tree[1].right = NULL;
//	tree[2].val = 5;
//	tree[2].left = NULL;
//	tree[2].right = NULL;
//	tree[3].val = 2;
//	tree[3].left = NULL;
//	tree[3].right = NULL;
//
//	Solution solution;
//	TreeNode *head = solution.Convert(tree);
//	while (head != NULL)
//	{
//		cout << head->val << ends;
//		head = head->right;
//	}
//	
//	
//	getchar();
//}