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
    vector<int> node_vals;
    void solution(TreeNode* root)
    {
        if(root==NULL)
            return;
        node_vals.push_back(root->val);
        if(root->left)
        {
            solution(root->left);
        }
        
        if(root->right)
        {
            solution(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) 
    {
        solution(root);
        sort(node_vals.begin(),node_vals.end());
        int min_val=INT_MAX;
        for(int i=1;i<node_vals.size();++i)
        {
            min_val=min(node_vals[i]-node_vals[i-1],min_val);
        }
        return min_val;
    }
};