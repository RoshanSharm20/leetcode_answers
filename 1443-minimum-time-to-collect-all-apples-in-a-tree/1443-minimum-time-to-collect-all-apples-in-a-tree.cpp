class Solution {
public:
    int count=0;
    int dfs(int src,vector<int> adj[],vector<bool>& hasApple,vector<bool>& visited)
    {
        visited[src]=true;
        int mid=0;
        for(auto it:adj[src])
        {
            if(!visited[it])
            {
                int t = dfs(it,adj,hasApple,visited);
                if(t)
                    count+=2;
                mid+=t;
            }
        }
        return hasApple[src]+mid;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<int> adj[n];
        vector<bool> visited(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,adj,hasApple,visited);
        return count;
    }
};