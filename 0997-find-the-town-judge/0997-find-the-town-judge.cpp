class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> adj[n+1];
        for(auto it:trust)
            adj[it[0]].push_back(it[1]);
        
        map<int,int> nodes;
        for(int i=1;i<=n;++i)
        {
            for(auto it:adj[i])
                nodes[it]++;
        }
        
        for(int i=1;i<=n;++i)
        {
            if(nodes[i]==n-1 && adj[i].size()==0)
                return i;
        }
        return -1;
    }
};