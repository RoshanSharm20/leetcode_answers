class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        vector<int> adj[n];
        for(int i=0;i<roads.size();++i)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        
        priority_queue<pair<int,int>> nodes;
        for(int i=0;i<n;++i)
        {
            int size = adj[i].size();
            nodes.push({size,i});
        }
        vector<int> weight(n,0);
        int count=n;
        while(!nodes.empty())
        {
            int node = nodes.top().second;
            nodes.pop();
            weight[node]=count;
            count--;
        }
        
        long long int ans = 0;
        for(int i=0;i<n;++i)
        {
            for(auto it:adj[i])
            {
                ans+=(weight[i]+weight[it]);
            }
        }
        ans=ans/2;
        return ans;
    }
};