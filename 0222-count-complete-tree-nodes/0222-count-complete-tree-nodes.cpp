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
    int countLeft(TreeNode* root)
    {
        int ht=0;
        while(root)
        {
            ht++;
            root=root->left;
        }
        return ht;
    }
    int countRight(TreeNode* root)
    {
        int rt=0;
        while(root)
        {
            rt++;
            root=root->right;
        }
        return rt;
    }
    int countNodes(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        
        int lh = countLeft(root);
        int rh = countRight(root);
        
        if(lh==rh)
            return (1<<lh)-1;
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};