class Solution {
public:
    int solution(int row,int col1,int col2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        if(col1<0 || col2<0 || col1>=grid[0].size() || col2>=grid[0].size())
            return -1e8;
        if(row==grid.size()-1)
            if(col1==col2)
                return grid[row][col1];
            else
                return grid[row][col1]+grid[row][col2];
        if(dp[row][col1][col2]!=-1)
            return dp[row][col1][col2];
        int maxi=-1e8;
        for(int dj1=-1;dj1<=1;++dj1)
        {
            for(int dj2=-1;dj2<=1;++dj2)
            {
                int value=0;
                if(col1==col2)
                    value=grid[row][col1];
                else
                    value=grid[row][col1]+grid[row][col2];
                value+=solution(row+1,col1+dj1,col2+dj2,grid,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[row][col1][col2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return solution(0,0,grid[0].size()-1,grid,dp);
    }
};