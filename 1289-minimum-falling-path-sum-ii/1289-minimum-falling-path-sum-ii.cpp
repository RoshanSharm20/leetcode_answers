class Solution {
public:
    int solution(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(row==0)
            return dp[row][col]=grid[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int min_val=1e9;
        for(int i=0;i<grid.size();++i)
        {
            if(i!=col)
            {
                int x = grid[row][col]+solution(row-1,i,grid,dp);
                min_val = min(min_val,x);
            }
        }
        return dp[row][col]=min_val;
    }
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();++i)
            solution(grid.size()-1,i,grid,dp);
        return *min_element(dp[grid.size()-1].begin(),dp[grid.size()-1].end());
    }
};