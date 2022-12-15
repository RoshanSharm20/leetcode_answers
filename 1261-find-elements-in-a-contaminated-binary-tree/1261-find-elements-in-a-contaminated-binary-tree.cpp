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
class FindElements {
public:
    vector<int> ans;
    FindElements(TreeNode* root) 
    {
        queue<TreeNode*> q;
        root->val=0;
        q.push(root);
        while(!q.empty())
        {
            int Size=q.size();
            for(int i=0;i<Size;++i)
            {
                TreeNode* node = q.front();
                q.pop();
                ans.push_back(node->val);
                if(node->left)
                {
                    node->left->val = (node->val*2) + 1;
                    q.push(node->left);
                }
                if(node->right)
                {
                    node->right->val = (node->val*2)+2;
                    q.push(node->right);
                }
            }
        }
    }
    
    bool find(int target) 
    {
        auto it = std::find (ans.begin(), ans.end(), target);
        if(it!=ans.end())
            return true;
        else
            return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */