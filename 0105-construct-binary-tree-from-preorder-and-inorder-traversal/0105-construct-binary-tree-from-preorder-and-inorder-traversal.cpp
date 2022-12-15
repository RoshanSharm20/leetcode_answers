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
    TreeNode* constructTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>& mNodes)
    {
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int index = mNodes[root->val];
        int nodesLeft = index-inStart;
        root->left=constructTree(preorder,preStart+1,preStart+nodesLeft,inorder,inStart,index-1,mNodes);
        root->right=constructTree(preorder,preStart+nodesLeft+1,preEnd,inorder,index+1,inEnd,mNodes);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int> mNodes;
        for(int i=0;i<inorder.size();++i)
        {
            mNodes[inorder[i]]=i;
        }
        TreeNode* root = constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mNodes);
        return root;
    }
};