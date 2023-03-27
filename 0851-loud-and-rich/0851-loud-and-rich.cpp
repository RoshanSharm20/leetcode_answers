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
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
    {
        //performing topological sort using dfs
        // making the adjacency list
        int n = quiet.size();
        vector<int> adj[n];
        for(int i=0;i<richer.size();++i)
        {
            adj[richer[i][0]].push_back(richer[i][1]);
        }
        
        vector<bool> visited(n,false);
        stack<int> st;
        vector<int> answer(n,0);
        for(int i=0;i<n;++i)
        {
            answer[i]=i;
        }
        for(int i=0;i<n;++i)
        {
            if(!visited[i])
                dfs(i,adj,visited,st);
        }
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            int person = answer[node];
            for(auto it:adj[node])
            {
                int checkperson = answer[it];
                if(quiet[person]<quiet[checkperson])
                {
                    answer[it]=person;
                }
            }
        }
        return answer;
    }
};