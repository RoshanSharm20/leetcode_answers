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
    TreeNode* solution(TreeNode* root1)
    {
        if(root1==NULL)
            return NULL;
        TreeNode* root2 = new TreeNode(root1->val);
        if(root1->left)
            root2->right = solution(root1->left);
        if(root1->right)
            root2->left = solution(root1->right);
        return root2;
    }
    TreeNode* invertTree(TreeNode* root1) 
    {
        if(root1==NULL)
            return root1;
        return solution(root1);
    }
};