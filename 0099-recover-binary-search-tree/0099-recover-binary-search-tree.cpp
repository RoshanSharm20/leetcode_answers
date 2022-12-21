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
    TreeNode* first=NULL;
    TreeNode* middle=NULL;
    TreeNode* last=NULL;
    TreeNode* prev=new TreeNode(INT_MIN);
    void solution(TreeNode* root)
    {
        if(root==NULL)
            return;
        solution(root->left);
        if(prev!=NULL && (prev->val > root->val))
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else
                last=root;
        }
        prev=root;
        solution(root->right);
    }
    void recoverTree(TreeNode* root) 
    {
        solution(root);
        if(first && last)
            swap(first->val,last->val);
        else if(first && middle)
            swap(first->val,middle->val);
    }
};