class Solution {
public:
    void dfs(int node,vector<int>& visited,int len,vector<int> adj[])
    {
        if(visited[node]!=INT_MAX)
            return;
        visited[node]=len;
        for(auto it:adj[node])
        {
            dfs(it,visited,len+1,adj);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        vector<int> adj[edges.size()];
        for(int i=0;i<edges.size();++i)
        {
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        }
        
        vector<int> visited1(edges.size(),INT_MAX);
        dfs(node1,visited1,0,adj);
        
        vector<int> visited2(edges.size(),INT_MAX);
        dfs(node2,visited2,0,adj);
        
        int max_len = INT_MAX;
        int index =-1;
        for(int i=0;i<edges.size();++i)
            edges[i]=max(visited1[i],visited2[i]);
        for(int i=0;i<edges.size();++i)
        {
            if(edges[i]<max_len)
            {
                max_len=edges[i];
                index=i;
            }
        }
        return index;
    }
};