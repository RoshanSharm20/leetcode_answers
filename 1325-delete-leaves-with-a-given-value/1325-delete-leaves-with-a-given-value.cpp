/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        if(root==NULL)
            return NULL;
        TreeNode* lt = removeLeafNodes(root->left,target);
        TreeNode* rt = removeLeafNodes(root->right,target);
        
        if(root->val == target && lt==NULL && rt==NULL)
        {
            root = NULL;
            return NULL;
        }
        else
        {
            root->left = lt;
            root->right = rt;
            return root;
        }
    }
};