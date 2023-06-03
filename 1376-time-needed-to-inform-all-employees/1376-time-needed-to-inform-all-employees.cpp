class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        // vector<bool> visited(n,false);
        vector<int> distance(n,1e9);
        distance[headID]=0;
        
        //producing the adjacency matrix
        vector<int> adj[n];
        for(int i=0;i<manager.size();++i)
        {
            if(manager[i]!=-1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> nodes;
        nodes.push({0,headID});
        while(!nodes.empty())
        {
            auto it = nodes.top();
            int cost = it.first;
            int node = it.second;
            nodes.pop();
            
            for(auto x : adj[node])
            {
                if(informTime[node]+cost<distance[x])
                {
                    distance[x]=informTime[node]+cost;
                    nodes.push({distance[x],x});
                }
            }
        }
        
        int max_val = *max_element(distance.begin(),distance.end());
        return max_val;
    }
};