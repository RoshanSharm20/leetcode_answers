class Solution {
public:
    bool dfs(vector<vector<int>>& adjacency,int source,int destination,vector<bool>& visited)
    {
        if(source == destination)
            return true;
        visited[source]=true;
        for(auto nodes:adjacency[source])
        {
            if(!visited[nodes])
            {
                if(dfs(adjacency,nodes,destination,visited))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>> adjacency(n);
        for(int i=0;i<edges.size();++i)
        {
            adjacency[edges[i][0]].push_back(edges[i][1]);
            adjacency[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        return dfs(adjacency,source,destination,visited);
    }
};