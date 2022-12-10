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
    int solution(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+max(solution(root->left),solution(root->right));
    }
    int maxDepth(TreeNode* root) 
    {
        //recursive approach
        if(root==NULL)
            return 0;
        return solution(root);
    }
};