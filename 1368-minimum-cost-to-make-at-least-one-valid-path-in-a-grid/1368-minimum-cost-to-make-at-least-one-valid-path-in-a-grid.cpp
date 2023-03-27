class Solution {
public:
    bool isValid(int nrow,int ncol,int n,int m)
    {
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
            return true;
        return false;
    }
    int minCost(vector<vector<int>>& grid) 
    {
        //solution using bfs 
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> distance(n,vector<int>(m,100000));
        vector<int> delrow = {0,0,1,-1};
        vector<int> delcol = {1,-1,0,0};
        queue<pair<int,int>> nodes;
        nodes.push({0,0});
        distance[0][0]=0;
        while(!nodes.empty())
        {
            int row = nodes.front().first;
            int col = nodes.front().second;
            nodes.pop();
            for(int i=0;i<4;++i)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(isValid(nrow,ncol,n,m))
                {
                    if(i+1 == grid[row][col] && distance[row][col]<distance[nrow][ncol])
                    {
                        distance[nrow][ncol]=distance[row][col];
                        nodes.push({nrow,ncol});
                    }
                    else if(distance[row][col]+1<distance[nrow][ncol])
                    {
                        distance[nrow][ncol]=distance[row][col]+1;
                        nodes.push({nrow,ncol});
                    }
                }
            }
        }
        return distance[n-1][m-1];
    }
};