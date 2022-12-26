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
    int count = 0;
    void solution(TreeNode* root,int max_val)
    {
        if(root==NULL)
            return;
        if(root->val>=max_val)
        {
            count++;
            max_val = max(max_val,root->val);
        }
        solution(root->left,max_val);
        solution(root->right,max_val);
    }
    int goodNodes(TreeNode* root) 
    {
        int max_val = root->val;
        solution(root,max_val);
        return count;
    }
};