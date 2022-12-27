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
    void inorder(TreeNode* root,vector<TreeNode*>& nodes,vector<int>& nodeValues)
    {
        if(root==NULL)
            return;
        inorder(root->left,nodes,nodeValues);
        nodes.push_back(root);
        nodeValues.push_back(root->val);
        inorder(root->right,nodes,nodeValues);
    }
    TreeNode* convertBST(TreeNode* root) 
    {
        vector<TreeNode*> nodes;
        vector<int> nodeValues;
        inorder(root,nodes,nodeValues);
        for(int i=nodeValues.size()-2;i>=0;--i)
        {
            nodeValues[i]=nodeValues[i]+nodeValues[i+1];
        }
        
        for(int i=0;i<nodes.size();++i)
        {
            nodes[i]->val = nodeValues[i];
        }
        return root;
    }
};