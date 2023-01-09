class Solution {
public:
    bool check(vector<int>& visited,int start,vector<vector<int>>& graph)
    {
        queue<int> nodes;
        nodes.push(start);
        visited[start]=0;
        while(!nodes.empty())
        {
            int index=nodes.front();
            nodes.pop();
            for(auto it : graph[index])
            {
                if(visited[it]==-1)
                {
                    visited[it]=!visited[index];
                    nodes.push(it);
                }
                else if(visited[it]==visited[index])
                    return false;
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        vector<int> visited(graph.size(),-1);
        for(int i=0;i<graph.size();++i)
        {
            if(visited[i]==-1)
            {
                if(check(visited,i,graph)==false)
                    return false;
            }
        }
        return true;
    }
};