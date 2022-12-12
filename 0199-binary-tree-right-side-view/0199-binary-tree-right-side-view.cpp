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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*,int>> q;
        map<int,int> m;
        q.push({root,0});
        while(!q.empty())
        {
            int Size=q.size();
            for(int i=0;i<Size;++i)
            {
                auto p = q.front();
                q.pop();
                m[p.second]=p.first->val;
                if(p.first->left)
                    q.push({p.first->left,p.second+1});
                if(p.first->right)
                    q.push({p.first->right,p.second+1});
            }
        }
        for(auto it : m)
            ans.push_back(it.second);
        return ans;
    }
};