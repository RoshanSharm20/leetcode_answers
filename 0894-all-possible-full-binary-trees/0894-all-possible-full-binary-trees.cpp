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
    vector<TreeNode*> solution(int n)
    {
        vector<TreeNode*> answer;
        if(n==1)
        {
            TreeNode* node = new TreeNode(0);
            answer.push_back(node);
            return answer;
        }
        
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left = solution(i);
            vector<TreeNode*> right = solution(n-i-1);
            
            for(auto it1: left)
                for(auto it2: right)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = it1;
                    root->right = it2;
                    answer.push_back(root);
                }
        }
        return answer;
    }
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        return solution(n);    
    }
};