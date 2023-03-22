class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
        int min_val=INT_MAX;
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<roads.size();++i)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<int> visited(n+1,false);
        queue<int> nodes;
        nodes.push(1);
        visited[1]=true;
        while(!nodes.empty())
        {
            auto node = nodes.front();
            nodes.pop();
            for(auto it : adj[node])
            {
                int next = it.first;
                // int cost = it.second;
                if(!visited[next])
                {
                    nodes.push(next);
                    // min_val = min(min_val,cost);
                    visited[next]=true;
                }
            }
        }
        for(int i=0;i<roads.size();++i)
        {
            if(visited[roads[i][0]] || visited[roads[i][1]])
                min_val = min(min_val,roads[i][2]);
        }
        return min_val;
    }
};