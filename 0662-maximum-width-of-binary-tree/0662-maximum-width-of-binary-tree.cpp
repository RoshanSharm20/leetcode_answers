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
    int widthOfBinaryTree(TreeNode* root) 
    {
        long long int max_width=INT_MIN;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            long long int first,last;
            long long int Size=q.size();
            long long int mini=q.front().second;
            for(long long int i=0;i<Size;++i)
            {
                auto p = q.front();
                long long int cur_id=p.second-mini;
                q.pop();
                if(i==0)
                    first=cur_id;
                if(i==Size-1)
                    last=cur_id;
                if(p.first->left)
                    q.push({p.first->left,(cur_id*2)+1});
                if(p.first->right)
                    q.push({p.first->right,(cur_id*2)+2});
            }
            max_width=max(max_width,last-first+1);
            
        }
        return max_width;
    }
};