/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solution(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL || root==p || root==q)
            return root;
        TreeNode* lt = solution(root->left,p,q);
        TreeNode* rt = solution(root->right,p,q);
        if(lt==NULL)
            return rt;
        if(rt==NULL)
            return lt;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return solution(root,p,q);    
    }
};