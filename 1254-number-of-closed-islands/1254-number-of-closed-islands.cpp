class Solution {
public:
    bool isValid(int nrow,int ncol,int n,int m)
    {
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
            return true;
        return false;
    }
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> nodes;
        visited[i][j]=true;
        nodes.push({i,j});
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        while(!nodes.empty())
        {
            auto it = nodes.front();
            nodes.pop();
            int row = it.first;
            int col = it.second;
            
            for(int x=0;x<4;++x)
            {
                int nrow = row + delrow[x];
                int ncol = col + delcol[x];
                
                if(isValid(nrow,ncol,n,m)&& grid[nrow][ncol]==0 && !visited[nrow][ncol])
                {
                    visited[nrow][ncol]=true;
                    nodes.push({nrow,ncol});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==0 && !visited[i][j])
                {
                    bfs(i,j,grid,visited);
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==0 && !visited[i][j])
                {
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        
        return count;
    }
};