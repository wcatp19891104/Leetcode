/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode *root, int lowband, int upband) {
        if(!root)
            return true;
        if(root->val <= lowband || root->val >= upband)
            return false;
        return helper(root->left, lowband, root->val) && helper(root->right, root->val, upband);
    }
    bool isValidBST(TreeNode *root) {
        return helper(root, INT_MIN, INT_MAX);
    }
    
   
};