/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            int x = nodes.size();
            vector<int> vec;
            for(int i=0;i<x;++i)
            {
                auto it = nodes.front();
                nodes.pop();
                vec.push_back(it->val);
                for(auto s:it->children)
                    nodes.push(s);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};