#include<iostream>
#include<vector>
using namespace::std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//class Solution {
//public:
//	bool isSameTree(TreeNode *p, TreeNode *q) {
//		result = true;
//		tra(p, q);
//		return result;
//	}
//	    vector<vector<int> > pathSum(TreeNode *root, int sum) {
//		line = vector<int>();
//		int _sum = 0;
//		vector<vector<int>> result;
//		result.clear();
//		//
//		tra(root);
//		for (int i = 0; i<storage.size(); i++)
//		{
//
//			for (int j = 0; j<storage[i].size(); j++)
//			{
//				_sum += storage[i][j];
//			}
//			if (_sum == sum)
//			{
//				result.push_back(storage[i]);
//				_sum = 0;
//			}
//			_sum = 0;
//		}
//		return result;
//	}
//private:
//
//	void tra(TreeNode *root)
//	{
//		if (root == NULL)
//		{
//			
//			return;
//		}
//			
//		line.push_back(root->val);
//		if (root->left != NULL)
//			tra(root->left);
//		if (root->right != NULL)
//			tra(root->right);
//		if ((root->left == NULL) && (root->right == NULL))
//		{
//			storage.push_back(line);
//			line.pop_back();
//		}
//			
//
//		return;
//	}
//	vector<int> line;
//	vector<vector<int>> storage;
//	bool result;
//};


 class Solution {
 public:
	 bool isSameTree(TreeNode *p, TreeNode *q) {
		 result = true;
		 tra(p, q);
		 return result;
	 }
 private:
	 void tra(TreeNode *p, TreeNode *q)
	 {
		 if ((p == NULL) && (q == NULL))
			 return;
		 if ((p == NULL) && (q != NULL))
		 {
			 result = false;
			 return;
		 }
		 if ((p != NULL) && (q == NULL))
		 {
			 result = false;
			 return;
		 }
		 if (p->val != q->val)
		 {
			 result = false;
			 return;
		 }
		 tra(p->left, q->left);
		 tra(p->right, q->right);
		 // return true;
	 }
	 bool result;
 };

void main()
{
	TreeNode* root_1 = new TreeNode(1);
	TreeNode* left_1 = new TreeNode(2);

	TreeNode* root_2 = new TreeNode(1);
	TreeNode* left_2 =  new TreeNode(2);
	root_1->left = left_1;
	root_2->right = left_2;

	Solution test;
	bool result = test.isSameTree(root_1, root_2);

	
}