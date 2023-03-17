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
    int maxDepth(Node* root) 
    {
        if(root==NULL)
            return 0;
        queue<Node*> nodes;
        nodes.push(root);
        int count=0;
        while(!nodes.empty())
        {
            count++;
            int x = nodes.size();
            for(int i=0;i<x;++i)
            {
                auto it = nodes.front();
                nodes.pop();
                for(auto vec : it->children)
                {
                    nodes.push(vec);
                }
            }
        }
        return count;
    }
};