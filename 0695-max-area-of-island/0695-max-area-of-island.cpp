class Solution {
public:
    int bfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& visited)
    {
        queue<pair<int,int>> nodes;
        nodes.push({row,col});
        visited[row][col]=true;
        int count=1;
        int n=grid.size(),m=grid[0].size();
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        while(!nodes.empty())
        {
            int x = nodes.front().first;
            int y = nodes.front().second;
            nodes.pop();
            for(int i=0;i<4;++i)
            {
                int nrow = x+delrow[i];
                int ncol = y+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol])
                {
                  nodes.push({nrow,ncol});
                  visited[nrow][ncol]=true;
                  count++;
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int max_val=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    int count = bfs(i,j,grid,visited);
                    max_val=max(max_val,count);
                }
            }
        }
        return max_val;    
    }
};