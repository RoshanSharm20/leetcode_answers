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
    int solution(TreeNode* root,int& diameter)
    {
        if(root==NULL)
            return 0;
        int lh=solution(root->left,diameter);
        int rh=solution(root->right,diameter);
        diameter=max(lh+rh,diameter);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter=0;
        solution(root,diameter);
        return diameter;
    }
};