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
    TreeNode* solution(int preStart,int preEnd,vector<int>& preorder,int postStart,int postEnd,vector<int>& postorder)
    {
        if(preStart>preEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd)
            return root;
        int index = postStart;
        while(preorder[preStart+1]!=postorder[index])
            index++;
        int len= index - postStart+ 1;
        root->left = solution(preStart+1,preStart+len,preorder,postStart,postStart+index,postorder);
        root->right = solution(preStart+len+1,preEnd,preorder,index+1,postEnd-1,postorder);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        return solution(0,preorder.size()-1,preorder,0,postorder.size()-1,postorder);    
    }
};