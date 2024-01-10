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
    int solution(TreeNode* start,unordered_map<TreeNode*,TreeNode*>& parents,unordered_map<TreeNode*,bool>& visited)
    {
        if(start==NULL || visited[start]==true)
            return 0;
        
        visited[start]=true;
        int x = solution(parents[start],parents,visited);
        
        int y = solution(start->left,parents,visited);
        int z = solution(start->right,parents,visited);
        
        return 1+max(x,max(y,z));
    }
    int amountOfTime(TreeNode* root, int start) 
    {
        unordered_map<TreeNode*,TreeNode*> parents;
        parents[root]=NULL;
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        TreeNode* st = NULL;
        while(!nodes.empty())
        {
            auto it = nodes.front();
            if(it->val==start)
                st=it;
            nodes.pop();
            
            if(it->left)
            {
                nodes.push(it->left);
                parents[it->left]=it;
            }
            
            if(it->right)
            {
                nodes.push(it->right);
                parents[it->right]=it;
            }
        }
        
        unordered_map<TreeNode*,bool> visited;
        return solution(st,parents,visited)-1;
    }
};