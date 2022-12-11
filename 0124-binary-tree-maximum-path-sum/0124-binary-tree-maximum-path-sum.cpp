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
    int solution(TreeNode* root,int& maxi)
    {
        if(root==NULL)
            return 0;
        int lhv=max(0,solution(root->left,maxi));
        int rhv=max(0,solution(root->right,maxi));
        maxi=max(maxi,lhv+rhv+root->val);
        return root->val+max(lhv,rhv);
    }
    int maxPathSum(TreeNode* root) 
    {
        int maxi=INT_MIN;
        solution(root,maxi);
        return maxi;
    }
};