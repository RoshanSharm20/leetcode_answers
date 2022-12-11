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
    int solution(TreeNode* root,map<int,int>& m)
    {
        if(root==NULL)
            return 0;
        int lhv=solution(root->left,m);
        int rhv=solution(root->right,m);
        int value = lhv+rhv+root->val;
        m[value]+=1;
        return value;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        map<int,int> m;
        solution(root,m);
        int max_freq=INT_MIN;
        for(auto it:m)
        {
            max_freq=max(max_freq,it.second);
        }
        vector<int> ans;
        for(auto it:m)
        {
            if(it.second==max_freq)
                ans.push_back(it.first);
        }
        return ans;
    }
};