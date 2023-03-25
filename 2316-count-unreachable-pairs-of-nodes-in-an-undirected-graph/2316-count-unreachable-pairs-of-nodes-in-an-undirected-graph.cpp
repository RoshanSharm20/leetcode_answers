class Solution {
public:
    void bfs(int index,vector<int> adj[],vector<bool>& visited,int& count)
    {
        queue<int> nodes;
        nodes.push(index);
        visited[index]=true;
        count++;
        while(!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    nodes.push(it);
                    visited[it]=true;
                    count++;
                }
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        // if(edges.size()==0)
        //     return (long long int)(0);
        vector<int> adj[n];
        for(int i=0;i<edges.size();++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n,false);
        vector<long long int> ans;
        for(int i=0;i<n;++i)
        {
            if(!visited[i])
            {
                int count=0;
                bfs(i,adj,visited,count);
                ans.push_back(count);
            }
        }
        vector<long long int> add(ans.size());
        long long int sum=0;
        add[ans.size()-1]=ans[ans.size()-1];
        for(int i=ans.size()-2;i>=0;--i)
        {
            add[i]=ans[i]+add[i+1];
        }
        for(int i=0;i<add.size()-1;++i)
        {
            sum+=(ans[i]*add[i+1]);
        }
        return sum;
    }
};