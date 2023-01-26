class Solution {
public:
    int dp[46];
    int solution(int n)
    {
        if(n==0 || n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int left = solution(n-1);
        int right = solution(n-2);
        return dp[n]=left+right;        
    }
    int climbStairs(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return solution(n);
    }
};