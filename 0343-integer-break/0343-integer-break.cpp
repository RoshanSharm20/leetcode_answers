class Solution {
public:
    int solution(int number,vector<int>& dp)
    {
        if(number==1)
            return 1;
        if(dp[number]!=-1)
            return dp[number];
        int maxi=number;
        for(int i=1;i<number;++i)
        {
            maxi=max(maxi,i*solution(number-i,dp));
        }
        return dp[number]=maxi;
    }
    int integerBreak(int n) 
    {
        vector<int> dp(n+1,-1);
        int maxi=-1e9;
        for(int i=1;i<n;++i)
        {
            maxi=max(maxi,i*solution(n-i,dp));
        }
        return maxi;
    }
};