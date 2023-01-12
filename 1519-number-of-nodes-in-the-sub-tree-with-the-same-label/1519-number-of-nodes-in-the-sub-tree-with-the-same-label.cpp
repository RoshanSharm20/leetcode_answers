class Solution {
public:
    map<char,int> dfs(int index,vector<int> adj[],string& labels,vector<int>& ans,vector<bool>& visited)
    {
        map<char,int> sub_val;
        visited[index]=true;
        for(auto it:adj[index])
        {
            if(!visited[it])
            {
                auto temp = dfs(it,adj,labels,ans,visited);
                for(auto i:temp)
                {
                    sub_val[i.first]+=i.second;
                }
            }
            else
            {
                sub_val[labels[it]]+=ans[it];
            }
        }
        sub_val[labels[index]]+=1;
        ans[index]=sub_val[labels[index]];
        return sub_val;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector<int> adj[n];
        for(int i=0;i<edges.size();++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n,0);
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i)
        {
            if(!visited[i])
                dfs(i,adj,labels,ans,visited);
        }
        return ans;
    }
};