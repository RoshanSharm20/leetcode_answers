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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ans;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            int x = nodes.size();
            int count=0;
            double sum=0;
            for(int i=0;i<x;++i)
            {
                auto it = nodes.front();
                nodes.pop();
                count++;
                sum+=it->val;
                if(it->left)
                    nodes.push(it->left);
                if(it->right)
                    nodes.push(it->right);
            }
            sum = sum/count;
            ans.push_back(sum);
        }
        return ans;
    }
};