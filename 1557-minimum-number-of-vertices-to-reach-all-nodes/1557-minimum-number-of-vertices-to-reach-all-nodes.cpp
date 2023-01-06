class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<bool> visited(n,false);
        for(int i=0;i<edges.size();++i)
                visited[edges[i][1]]=true;
        vector<int> ans;
        for(int i=0;i<visited.size();++i)
        {
            if(!visited[i])
                ans.push_back(i);
        }
        return ans;
    }
};