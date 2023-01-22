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
    TreeNode* solution(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL || root2==NULL)
        {
            if(root1)
                return root1;
            else if(root2)
                return root2;
            else
                return NULL;
        }
        TreeNode* root = new TreeNode(0);
        if(root1 && root2)
        {
            root->val = root1->val + root2->val;
            root->left = solution(root1->left,root2->left);
            root->right = solution(root1->right,root2->right);
        }
        else if(root1)
        {
            root->val = root1->val;
            root->left = solution(root1->left,NULL);
            root->right = solution(root->right,NULL);
        }
        else
        {
            root->val = root2->val;
            root->left = solution(NULL,root2->left);
            root->right = solution(NULL,root2->right);
        }
        
        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        return solution(root1,root2);    
    }
};