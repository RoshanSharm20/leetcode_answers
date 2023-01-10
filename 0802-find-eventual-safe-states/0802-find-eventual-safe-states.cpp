class Solution {
public:
    bool dfs(int index,vector<vector<int>>& graph,vector<int>& visited,vector<int>& pathVisited,vector<int>& check)
    {
        visited[index]=1;
        pathVisited[index]=1;
        check[index]=0;
        for(auto it:graph[index])
        {
            if(!visited[it])
            {
                if(dfs(it,graph,visited,pathVisited,check))
                {
                    check[index]=0;
                    return true;
                }
            }
            else if(pathVisited[it])
            {
                check[index]=0;
                return true;
            }
        }
        check[index]=1;
        pathVisited[index]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<int> visited(graph.size(),0);
        vector<int> pathVisited(graph.size(),0);
        vector<int> check(graph.size(),0);
        for(int i=0;i<graph.size();++i)
        {
            if(visited[i]==0)
                dfs(i,graph,visited,pathVisited,check);
        }
        vector<int> ans;
        for(int i=0;i<check.size();++i)
        {
            if(check[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};