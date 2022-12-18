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
    void solution(TreeNode* root,string asf,vector<string>& ans)
    {
        asf+=to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(asf);
            return;
        }
        
        if(root->left)
            solution(root->left,asf+"->",ans);
        if(root->right)
            solution(root->right,asf+"->",ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;
        solution(root,"",ans);
        return ans;
    }
};