class Solution {
public:
    int solution(int row,int col,vector<vector<int>>& Grid,vector<vector<int>>& dp)
    {
        if(row>=0 && col>=0 && Grid[row][col]==1)
            return 0;
        if(row==0 && col==0)
            return 1;
        if(row<0 || col<0)
            return 0;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int up=0,left=0;
        if(row>0)
            up = solution(row-1,col,Grid,dp);
        if(col>0)
            left = solution(row,col-1,Grid,dp);
        return dp[row][col]=up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) 
    {
        vector<vector<int>> dp(Grid.size(),vector<int>(Grid[0].size(),-1));
        return solution(Grid.size()-1,Grid[0].size()-1,Grid,dp);    
    }
};