class Solution {
public:
    int solution(int index,vector<int>& coins,vector<vector<int>>& dp,int target)
    {
        if(index==0)
        {
            if(target%coins[0]==0)
                return target/coins[0];
            else
                return 1e9;
        }
        
        if(dp[index][target]!=-1)
            return dp[index][target];
        
        int nottake = solution(index-1,coins,dp,target);
        int take=1e9;
        if(coins[index]<=target)
            take = 1+solution(index,coins,dp,target-coins[index]);
        return dp[index][target]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = solution(coins.size()-1,coins,dp,amount);
        if(ans>=1e9)
            return -1;
        return ans;
    }
};