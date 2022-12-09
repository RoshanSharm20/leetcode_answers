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
    int solution(TreeNode* root,int maxi,int mini,int result)
    {
        if(root==NULL)
        {
            return result;
        }
        if(abs(maxi-root->val)>result)
            result=abs(maxi-root->val);
        if(abs(mini-root->val)>result)
            result=abs(mini-root->val);
        result=max(solution(root->left,max(maxi,root->val),min(mini,root->val),result),result);
        result=max(solution(root->right,max(maxi,root->val),min(mini,root->val),result),result);
        return result;
    }
    int maxAncestorDiff(TreeNode* root) 
    {
        return solution(root,root->val,root->val,0);
    }
};