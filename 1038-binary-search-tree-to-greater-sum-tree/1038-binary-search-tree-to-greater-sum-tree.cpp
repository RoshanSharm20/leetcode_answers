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
    void inorder(TreeNode* root,vector<int>& order)
    {
        if(root==NULL)
            return;
        inorder(root->left,order);
        order.push_back(root->val);
        inorder(root->right,order);
    }
    void solution(TreeNode* root,vector<int>& order)
    {
        if(root==NULL)
            return;
        solution(root->left,order);
        auto it = find(order.begin(),order.end(),root->val);
        int sum = accumulate(it,order.end(),0);
        root->val=sum;
        solution(root->right,order);
    }
    TreeNode* bstToGst(TreeNode* root) 
    {
        vector<int> order;
        inorder(root,order);
        solution(root,order);
        return root;
    }
};