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
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int count = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            int size = nodes.size();
            for(int i=0;i<size;++i)
            {
                auto it = nodes.front();
                nodes.pop();
                if(it->val>=low && it->val<=high)
                    count+=it->val;
                if(it->left)
                    nodes.push(it->left);
                if(it->right)
                    nodes.push(it->right);
            }
        }
        return count;
    }
};