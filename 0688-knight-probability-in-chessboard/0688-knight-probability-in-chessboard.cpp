class Solution {
public:
    double solution(vector<vector<vector<double>>> &dp,int n,int k,int row,int col)
    {
        if(k<0)
            return 1;
        if(row<0 || col<0 || row>=n || col>=n)
            return 0;
        if(dp[row][col][k]!=-1)
            return dp[row][col][k];
        
        vector<int> delrow = { 2, 1, -1, -2, -2, -1, 1, 2 };
        vector<int> delcol = { 1, 2, 2, 1, -1, -2, -2, -1 };
        double ans=0;
        for(int i=0;i<8;++i)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            ans+=solution(dp,n,k-1,nrow,ncol);
        }
        return dp[row][col][k]=ans/8;
    }
    double knightProbability(int n, int k, int row, int column) 
    {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solution(dp,n,k,row,column);
    }
};