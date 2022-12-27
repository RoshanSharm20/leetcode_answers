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
    vector<vector<int>> answer;
    void solution(TreeNode* root,vector<int>& nodes,int& targetSum,int currSum)
    {
        if(root==NULL)
        {
            return;
        }
        currSum+=root->val;
        nodes.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(currSum==targetSum)
            {
                answer.push_back(nodes);
            }
        }
        else
        {
            solution(root->left,nodes,targetSum,currSum);
            solution(root->right,nodes,targetSum,currSum);
        }
        nodes.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> nodes;
        solution(root,nodes,targetSum,0);
        return answer;
    }
};
