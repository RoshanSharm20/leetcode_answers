class Solution {
public:
    int ans=0;
    int dfs(int src,vector<int> adj[],string &s,vector<int>&visited)
    {
        visited[src]=1;
        int mx1=0;
        int mx2=0;
        for(auto &i:adj[src]){
            if(visited[i]==0){
                int t = dfs(i,adj,s,visited);
                ans = max(ans,t);
                if(s[src]!=s[i]){
                    if(mx1<=t){
                        mx2 = mx1;
                        mx1 = t;
                    }
                    else
                    mx2 = max(mx2,t);
                    ans = max(ans,mx1+mx2+1);
                }
            }
        }
        return mx1+1;
        
        
    }
    int longestPath(vector<int>& parent, string s) 
    {
        vector<int> adj[parent.size()];
        vector<int>visited(parent.size());

        for(int i=1;i<parent.size();++i)
        {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        int i = dfs(0,adj,s,visited);
        return max(ans,i);
    }
};