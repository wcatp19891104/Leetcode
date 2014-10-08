#include<stack>
#include<vector>
#include<unordered_set>
#include<string>
using namespace::std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode*> ret;
		vector<int> res = vector<int>(0);
		if (root == NULL)
			return res;
		if ((!root->left) && (!root->right))
		{
			res.push_back(root->val);
			return res;
		}
		TreeNode* temp = root;
		while ((ret.size() != 0) || (temp != NULL))
		{
			if (temp != NULL)
			{
				ret.push(temp);
				//ret.push(temp->left);
				temp = temp->left;
			}
			else
			{
				temp = ret.top();
				ret.pop();
				res.push_back(temp->val);
				temp = temp->right;
			}
		}
		return res;
	}
};


void main()
{
	/*TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	n1->val = 1;
	n2->val = 2;
	n1->left = n2;
	Solution t;
	t.inorderTraversal(n1);*/
	/*char a = 'a', b = 'b';
	unordered_set<char> t;
	t.emplace('a');
	t.emplace('b');
	unordered_set < char>::iterator it;
	it = t.find('c');
	auto x = t.end();
	string s;*/
	const int n = 3;
	int a[n];
}