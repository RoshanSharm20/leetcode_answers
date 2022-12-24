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
    TreeNode* solution(vector<int> order)
    {
        if(order.size()==0)
            return NULL;
        int index = order.size()/2;
        TreeNode* root = new TreeNode(order[index]);
        vector<int> la(order.begin(),order.begin()+index);
        vector<int> ra(order.begin()+index+1,order.end());
        root->left = solution(la);
        root->right = solution(ra);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> order;
        inorder(root,order);
        int index = order.size()/2;
        TreeNode* root1 = new TreeNode(order[index]);
        vector<int> la(order.begin(),order.begin()+index);
        vector<int> ra(order.begin()+index+1,order.end());
        root1->left = solution(la);
        root1->right = solution(ra);
        return root1;
    }
};