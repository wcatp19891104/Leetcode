#include<stack>
#include<queue>
using namespace::std;


struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		if (root->left == NULL)
		{
			root->next = NULL;
			return;
		}
		stack1.push(root);
		stack2.push(root->left);
		stack2.push(root->right);
		while (stack1.size() != 0)
		{
			int size1 = stack1.size();
			int size2 = stack2.size();
			int count = size2;
			while (stack1.size() != 0)
			{
				if (stack1.size() == 1)
				{
					stack1.front()->next = NULL;
					stack1.pop();
				}
				else
				{
					TreeLinkNode* temp = stack1.front();
					stack1.pop();
					temp->next = stack1.front();
				}
			}
			while (count != 0)
			{
				if (stack2.front()->left != NULL)
				{
					stack2.push(stack2.front()->left);
					stack2.push(stack2.front()->right);
				}
				stack1.push(stack2.front());
				stack2.pop();
				count--;
			}
		}

	}
private:
	queue<TreeLinkNode*> stack1;
	queue<TreeLinkNode*> stack2;
};


void main()
{

	TreeLinkNode* t0 = new TreeLinkNode(0);
	TreeLinkNode* t1 = new TreeLinkNode(1);
	TreeLinkNode* t2 = new TreeLinkNode(2);
	TreeLinkNode* t3 = new TreeLinkNode(3);
	TreeLinkNode* t4 = new TreeLinkNode(4);
	TreeLinkNode* t5 = new TreeLinkNode(5);
	TreeLinkNode* t6 = new TreeLinkNode(6);
	t0->left = t1;
	t0->right = t2;
	t1->left = t3;
	t1->right = t4;
	t2->left = t5;
	t2->right = t6;
	Solution test;
	test.connect(t0);
}