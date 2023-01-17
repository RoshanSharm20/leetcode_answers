class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int,int>> adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>> nodes;
        vector<int> distance(n,INT_MAX);
        distance[src]=0;
        nodes.push({0,{src,0}});
        while(!nodes.empty())
        {
            auto it = nodes.front();
            nodes.pop();
            int stops = it.first;
            int node = it.second.first;
            int wt = it.second.second;
            if(stops>k)
                continue;
            for(auto i:adj[node])
            {
                int adjnode = i.first;
                int weight = i.second;
                if(wt+weight<distance[adjnode] && stops<=k)
                {
                    distance[adjnode]=wt+weight;
                    nodes.push({1+stops,{adjnode,distance[adjnode]}});
                }
            }
        }
        if(distance[dst]==INT_MAX)
            return -1;
        return distance[dst];
    }
};