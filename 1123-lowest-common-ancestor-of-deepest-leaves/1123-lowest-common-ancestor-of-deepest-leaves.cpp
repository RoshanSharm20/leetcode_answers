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
    TreeNode* solution(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL || root==p || root==q)
            return root;
        
        TreeNode* lt=solution(root->left,p,q);
        TreeNode* rt=solution(root->right,p,q);
        
        if(lt==NULL)
            return rt;
        else if(rt==NULL)
            return lt;
        else
            return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        //performing the level order traversal
        queue<TreeNode*> q;
        vector<TreeNode*> nodes;//to store the leafNodes
        q.push(root);
        while(!q.empty())
        {
            int Size=q.size();
            vector<TreeNode*> temp;
            for(int i=0;i<Size;++i)
            {
                auto node = q.front();
                temp.push_back(node);
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            nodes=temp;
        }
        if(nodes.size()==1)
            return nodes[0];
        TreeNode* temp=nodes[0];
        for(int i=1;i<nodes.size();++i)
        {
            temp=solution(root,temp,nodes[i]);
            if(temp==root)
                return root;
        }
        return temp;
    }
};