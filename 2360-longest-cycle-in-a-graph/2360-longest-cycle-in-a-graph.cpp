class Solution {
public:
    void dfs(int index,vector<int> adj[],vector<bool>& visited,stack<int>& st)
    {
        visited[index]=true;
        for(auto it:adj[index])
        {
            if(!visited[it])
                dfs(it,adj,visited,st);
        }
        st.push(index);
    }
    
    
    
    void dfs3(int index,vector<int> adjt[],vector<bool>& vis,int& count)
    {
        vis[index]=true;
        count++;
        for(auto it:adjt[index])
        {
            if(!vis[it])
                dfs3(it,adjt,vis,count);
        }
    }
    
    
    
    int longestCycle(vector<int>& edges) 
    {
        //creating an adjacency list
        int n = edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;++i)
        {
            if(edges[i]!=-1)
            {
                adj[i].push_back(edges[i]);
            }
        }
        
        //performing the topological sort for the nodes according to their finishing time
        vector<bool> visited(n,false);
        stack<int> st;
        for(int i=0;i<n;++i)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,st);
            }
        }
        
        //reversing the graph
        vector<int> adjt[n];
        for(int i=0;i<n;++i)
        {
            if(edges[i]!=-1)
            {
                adjt[edges[i]].push_back(i);
            }
        }
        
        //performing dfs for the reversed graph
        vector<bool> vis(n,false);
        int max_count=1;
        while(!st.empty())
        {
            int i = st.top();
            st.pop();
            int count=0;
            if(!vis[i])
            {
                dfs3(i,adjt,vis,count);
                max_count = max(max_count,count);
            }
        }
        
        if(max_count==1)
            return -1;
        return max_count;
    }
};