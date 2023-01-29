//memoization
class Solution {
public:
    int solution(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(row==0 && col==0)
            return grid[0][0];
        if(row<0 || col<0)
            return 10000;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int up = grid[row][col]+solution(row-1,col,grid,dp);
        int left = grid[row][col]+solution(row,col-1,grid,dp);
        return dp[row][col]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solution(grid.size()-1,grid[0].size()-1,grid,dp);
    }
};