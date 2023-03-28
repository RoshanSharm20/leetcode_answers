/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*>& visited)
    {
        // visited.insert(node);
        if(node==NULL)
            return NULL;
        int value = node->val;
        Node* root = new Node(value);
        
        visited[node]=root;
        
        for(auto it:node->neighbors)
        {
            if(visited.find(it)==visited.end())
            {
                auto x = dfs(it,visited);
                root->neighbors.push_back(x);
            }
            else
            {
                root->neighbors.push_back(visited[it]);
            }
            
        }
        return root;
    }
    Node* cloneGraph(Node* node) 
    {
        unordered_map<Node*,Node*> visited;
        return dfs(node,visited);
    }
};