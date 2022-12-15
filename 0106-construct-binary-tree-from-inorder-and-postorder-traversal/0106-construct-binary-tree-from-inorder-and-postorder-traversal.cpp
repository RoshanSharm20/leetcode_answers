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
    TreeNode* constructTree(vector<int>& postorder,int postStart,int postEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>& mNodes)
    {   
        if(postStart>postEnd || inStart>inEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int index = mNodes[root->val];
        int nodesLeft = index-inStart;
        root->left = constructTree(postorder,postStart,postStart+nodesLeft-1,inorder,inStart,index-1,mNodes);
        root->right = constructTree(postorder,postStart+nodesLeft,postEnd-1,inorder,index+1,inEnd,mNodes);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        map<int,int> mNodes;
        for(int i=0;i<inorder.size();++i)
        {
            mNodes[inorder[i]]=i;
        }
        TreeNode* root= constructTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mNodes);
        return root;
    }
};