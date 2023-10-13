class Solution {
public:
    int solution(int index,vector<int> &cost,vector<int> &dp)
    {
        if(index>=cost.size())
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        int ans = cost[index];
        ans = min(ans+solution(index+1,cost,dp),ans+solution(index+2,cost,dp));
        
        return dp[index]=ans;
        
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        vector<int> dp(n,-1);
        solution(0,cost,dp);
        return min(dp[0],dp[1]);
    }
};