class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();++i)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> distance(n+1,1000);
        distance[0]=-1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> nodes;
        nodes.push({0,k});
        distance[k]=0;
        while(!nodes.empty())
        {
            int dis = nodes.top().first;
            int node = nodes.top().second;
            nodes.pop();
            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int weight = it.second;
                if(dis+weight<distance[adjnode])
                {
                    distance[adjnode]=dis+weight;
                    nodes.push({distance[adjnode],adjnode});
                }
            }
        }
        int max_val = *max_element(distance.begin(),distance.end());
        if(max_val==1000)
            return -1;
        return max_val;
        
    }
};