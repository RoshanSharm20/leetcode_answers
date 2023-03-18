class Solution {
public:
    long long int sum=0;
    long long int dfs(int index,int parent,vector<int> adj[],int seats)
    {
        int count_nodes=0;
        for(auto it : adj[index])
        {
            if(it!=parent)
            {
                count_nodes+=dfs(it,index,adj,seats);
            }
        }
        count_nodes++;
        sum+=count_nodes/seats;
        if(count_nodes%seats!=0)
            sum+=1;
        return count_nodes;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        int n = roads.size();
        vector<int> adj[n+1];
        for(int i=0;i<n;++i)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        // long long int ans=0;
        for(auto it:adj[0])
            dfs(it,0,adj,seats);
        return sum;
    }
};