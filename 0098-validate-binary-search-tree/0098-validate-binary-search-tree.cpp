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
    bool solution(TreeNode* root,long int mini,long int maxi)
    {
        if(root==NULL)
            return true;
        if(root->val<=mini || root->val>=maxi)
            return false;
        return (solution(root->left,mini,root->val) && solution(root->right,root->val,maxi));
    }
    bool isValidBST(TreeNode* root) 
    {
        return solution(root,LONG_MIN,LONG_MAX);    
    }
};