class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<int>& time,vector<int>& lowest,vector<bool>& visited,vector<vector<int>>& bridges,vector<int> adj[])
    {
        if(visited[node])
            return;
        visited[node]=true;
        time[node]=timer;
        lowest[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==parent)
                continue;
            if(!visited[it])
            {
                dfs(it,node,time,lowest,visited,bridges,adj);
                lowest[node]=min(lowest[node],lowest[it]);
                if(lowest[it]>time[node])
                    bridges.push_back({it,node});
            }
            else
            {
                lowest[node]=min(lowest[node],lowest[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        //create the adjacency list
        vector<int> adj[n];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //we require the time of insertion and lowest time vector of all edges
        vector<int> time(n),lowest(n);
        //visited vector is required to keep track of visited nodes;
        vector<bool> visited(n,false);
        //bridges vector to store the bridges
        vector<vector<int>> bridges;
        dfs(0,-1,time,lowest,visited,bridges,adj);
        return bridges;
    }
};