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
    void solution(TreeNode *root,unordered_map<int,int> &nodes)
    {
        if(!root)
            return;
        nodes[root->val]+=1;
        solution(root->left,nodes);
        solution(root->right,nodes);
    }
    vector<int> findMode(TreeNode* root) 
    {
        unordered_map<int,int> nodes;
        vector<int> ans;
        solution(root,nodes);
        int max_val = 0;
        for(auto it:nodes)
        {
            if(it.second>max_val)
                max_val = it.second;
        }
        
        for(auto it:nodes)
        {
            if(it.second==max_val)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};