/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findParent(TreeNode* root,map<TreeNode*,TreeNode*>& parent_record)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int Size=q.size();
            for(int i=0;i<Size;++i)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                {
                    parent_record[node->left]=node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    parent_record[node->right]=node;
                    q.push(node->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        map<TreeNode*,TreeNode*> parent_record;
        findParent(root,parent_record);
        map<TreeNode*,bool>visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int curr_level=0;
        while(!q.empty())
        {
            int Size=q.size();
            if(curr_level==k)
                break;
            for(int i=0;i<Size;++i)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent_record[node] && !visited[parent_record[node]])
                {
                    q.push(parent_record[node]);
                    visited[parent_record[node]]=true;
                }

            }
            curr_level++;
        }
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};