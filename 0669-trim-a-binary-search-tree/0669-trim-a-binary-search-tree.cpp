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
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if(root==NULL)
            return NULL;
        TreeNode* lt = trimBST(root->left,low,high);
        TreeNode* rt = trimBST(root->right,low,high);
        if(root->val>=low && root->val<=high)
        {
            root->left = lt;
            root->right = rt;
            return root;
        }
        
        if(lt && lt->val>=low && lt->val<=high)
            return lt;
        else if(rt && rt->val>=low && rt->val<=high)
            return rt;
        else
            return NULL;
    }
};