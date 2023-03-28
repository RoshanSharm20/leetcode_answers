class Solution {
public:
    int count=0;
    void dfs(int index,vector<int> adj[],unordered_set<int>& noNodes,vector<bool>& visited)
    {
        visited[index]=true;
        count++;
        for(auto it:adj[index])
        {
            if(!visited[it] && noNodes.find(it)==noNodes.end())
                dfs(it,adj,noNodes,visited);
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {
        vector<int> adj[n];
        for(int i=0;i<edges.size();++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        unordered_set<int> noNodes;
        for(int i=0;i<restricted.size();++i)
            noNodes.insert(restricted[i]);
        
        vector<bool> visited(n,false);
        dfs(0,adj,noNodes,visited);
        return count;
    }
};