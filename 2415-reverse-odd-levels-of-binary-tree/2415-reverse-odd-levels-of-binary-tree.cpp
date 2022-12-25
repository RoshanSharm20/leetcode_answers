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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = 0;
        while(!nodes.empty())
        {
            int Size = nodes.size();
            if(level%2!=0)
            {
                vector<TreeNode*> levelNodes;
                for(int i=0;i<Size;++i)
                {
                    TreeNode* node = nodes.front();
                    nodes.pop();
                    levelNodes.push_back(node);
                    if(node->left)
                        nodes.push(node->left);
                    if(node->right)
                        nodes.push(node->right);
                }
                for(int i=0;i<(levelNodes.size()/2);++i)
                {
                    int x = levelNodes[i]->val;
                    int y = levelNodes[levelNodes.size()-i-1]->val;
                    levelNodes[i]->val = y;
                    levelNodes[levelNodes.size()-i-1]->val = x;
                }
            }
            else
            {
                for(int i=0;i<Size;++i)
                {
                    TreeNode* node = nodes.front();
                    nodes.pop();
                    if(node->left)
                        nodes.push(node->left);
                    if(node->right)
                        nodes.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};