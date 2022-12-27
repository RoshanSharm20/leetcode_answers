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
    vector<TreeNode*> solution(int start,int end)
    {
        vector<TreeNode*> answer;
        if(start>end)
        {
            answer.push_back(NULL);
            return answer;
        }
        for(int i=start;i<=end;++i)
        {
            vector<TreeNode*> left = solution(start,i-1);
            vector<TreeNode*> right = solution(i+1,end);
            for(auto it1 : left)
                for(auto it2 : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = it1;
                    root->right = it2;
                    answer.push_back(root);
                }
        }
        return answer;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
        return solution(1,n);
    }
};