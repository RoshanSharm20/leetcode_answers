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
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*> q;
        int level=0;
        int i=1;
        int max_val=INT_MIN;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            int sum=0;
            vector<int>temp;
            for(int i=0;i<size;++i)
            {
                TreeNode* node=q.front();
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                q.pop();
                sum+=node->val;
            }
            if(sum>max_val)
            {
                max_val=sum;
                level=i;
            }
            i++;
        }
        return level;
    }
};