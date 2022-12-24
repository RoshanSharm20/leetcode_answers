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
    int count=0;
    int solution(TreeNode* root,map<TreeNode*,int>& no_of_nodes)
    {
        if(root==NULL)
            return -1;
        int lt = solution(root->left,no_of_nodes);
        int rt = solution(root->right,no_of_nodes);
        int sum=0,ld=0,rd=0;
        if(lt!=-1)
        {
            sum+=lt;
            ld=no_of_nodes[root->left];
        }
        if(rt!=-1)
        {
            sum+=rt;
            rd=no_of_nodes[root->right];
        }
        
        no_of_nodes[root]=ld+rd+1;
        sum+=root->val;
        if(root->val==(sum/(ld+rd+1)))
            count++;
        return sum;
    }
    int averageOfSubtree(TreeNode* root) 
    {
        map<TreeNode*,int> no_of_nodes;
        solution(root,no_of_nodes);
        return count;
    }
};