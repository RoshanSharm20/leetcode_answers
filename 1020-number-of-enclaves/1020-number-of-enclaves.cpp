class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> nodes;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        nodes.push({i,j});
                        visited[i][j]=true;
                    }
                }
            }
        }
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        while(!nodes.empty())
        {
            auto it = nodes.front();
            nodes.pop();
            for(int i=0;i<4;++i)
            {
                int nrow = it.first + delrow[i];
                int ncol = it.second + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol])
                {
                    nodes.push({nrow,ncol});
                    visited[nrow][ncol]=true;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1 && !visited[i][j])
                    count++;
            }
        }
        return count;
    }
};
// vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
//         queue<pair<int,int>> nodes;
//         int n = grid.size();;
//         int m = grid[0].size();
//         int count=0;
//         for(int i=0;i<m;++i)
//         {
//             if(grid[0][i]==1)
//             {
//                 nodes.push({0,i});
//                 visited[0][i]=true;
//                 count++;
//             }
//         }
//         for(int i=0;i<m;++i)
//         {
//             if(grid[n-1][i]==1)
//             {
//                 nodes.push({n-1,i});
//                 visited[n-1][i]=true;
//                 count++;
//             }
//         }
//         for(int i=0;i<n;++i)
//         {
//             if(grid[i][0]==1)
//             {
//                 nodes.push({i,0});
//                 visited[i][0]=true;
//                 count++;
//             }
//         }
//         for(int i=0;i<n;++i)
//         {
//             if(grid[i][m-1]==1)
//             {
//                 nodes.push({i,m-1});
//                 visited[i][m-1]=true;
//                 count++;
//             }
//         }
//         vector<int> delrow = {0,-1,0,1};
//         vector<int> delcol = {-1,0,1,0};
//         while(!nodes.empty())
//         {
//             auto it = nodes.front();
//             nodes.pop();
//             for(int i=0;i<4;++i)
//             {
//                 int newrow = it.first+delrow[i];
//                 int newcol = it.second+delcol[i];
//                 if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1 && !visited[newrow][newcol])
//                 {
//                     nodes.push({newrow,newcol});
//                     count++;
//                     visited[newrow][newcol]=true;
//                 }
//             }
//         }
//         int count_zero=0;
//         for(int i=0;i<grid.size();++i)
//         {
//             for(int j=0;j<grid[0].size();++j)
//             {
//                 if(grid[i][j]==0)
//                     count_zero++;
//             }
//         }
//         return ((n*m)-(count_zero + count));