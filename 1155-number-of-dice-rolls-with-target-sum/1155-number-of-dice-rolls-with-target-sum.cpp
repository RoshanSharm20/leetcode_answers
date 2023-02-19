class Solution {
public:
    int mod = 1e9+7;
    int solution(int n,int target,int& k,vector<vector<int>>& dp)
    {
        if(n==1)
        {
            if(target>=1 && target<=k)
                return 1;
            return 0;
        }
        
        if(target==0)
        {
            return 0;
        }
        
        if(dp[n][target]!=-1)
            return dp[n][target];
        
        int x = 0;
        for(int i=1;i<=k;++i)
        {
            if(target-i>=0)
            {
                x=(x+solution(n-1,target-i,k,dp))%mod;
            }
        }
        x=x%mod;
        return dp[n][target]=x;
    }
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solution(n,target,k,dp);
    }
};