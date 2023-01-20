class Solution {
public:
    int total_count=0;
    void solution(vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y,int x1,int y1,int count,int total)
    {
        if(x==x1 && y==y1 && count==total)
        {
            total_count++;
            return;
        }
        
        visited[x][y]=true;
        vector<int> delrow={0,-1,0,1};
        vector<int> delcol={-1,0,1,0};
        for(int i=0;i<4;++i)
        {
            int nrow=x+delrow[i];
            int ncol=y+delcol[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]!=-1 && !visited[nrow][ncol])
            {
                solution(grid,visited,nrow,ncol,x1,y1,count+1,total);
            }
        }
        visited[x][y]=false;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int x=0;
        int y=0;
        int x1=0;
        int y1=0;
        int total=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                }
                if(grid[i][j]==2)
                {
                    x1=i;
                    y1=j;
                }
                if(grid[i][j]==0||grid[i][j]==1)
                    total++;
            }
        }
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        solution(grid,visited,x,y,x1,y1,0,total);
        return total_count;
    }
};