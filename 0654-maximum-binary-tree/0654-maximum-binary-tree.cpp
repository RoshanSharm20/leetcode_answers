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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        if(nums.size()==0)
            return NULL;
        auto it = max_element(nums.begin(),nums.end());
        int index = it-nums.begin();
        TreeNode* root = new TreeNode(nums[index]);
        vector<int> la(nums.begin(),nums.begin()+index);
        vector<int> ra(nums.begin()+index+1,nums.end());
        root->left = constructMaximumBinaryTree(la);
        root->right = constructMaximumBinaryTree(ra);
        return root;
        
    }
};