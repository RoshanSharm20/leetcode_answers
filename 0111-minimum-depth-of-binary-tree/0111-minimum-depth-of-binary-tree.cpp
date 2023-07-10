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
    bool isLeaf(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL)
            return true;
        return false;
    }
    void solution(TreeNode* root,int count,int &min_val)
    {
        if(isLeaf(root))
        {
            min_val=min(min_val,count);
            return;
        }
        
        if(root->left)
            solution(root->left,count+1,min_val);
        if(root->right)
            solution(root->right,count+1,min_val);
    }
    int minDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        int min_val=INT_MAX;
        solution(root,1,min_val);
        return min_val;
    }
};