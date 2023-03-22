class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> nodes;
        if(grid[0][0]!=1)
            {nodes.push({1,{0,0}});
            dist[0][0]=1;}
        while(!nodes.empty())
        {
            auto it = nodes.top();
            nodes.pop();
            int steps = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for(int i=-1;i<=1;++i)
            {
                for(int j=-1;j<=1;++j)
                {
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0)
                    {
                        if(steps + 1 <dist[nrow][ncol])
                        {
                            dist[nrow][ncol]=steps+1;
                            nodes.push({steps+1,{nrow,ncol}});
                        }
                    }
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX)
            return -1;
        return dist[n-1][n-1];
    }
};