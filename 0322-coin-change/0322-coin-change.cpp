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
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        for(int t=0;t<=amount;++t)
        {
            if(t%coins[0]==0)
                dp[0][t]=t/coins[0];
            else
                dp[0][t]=1e9;
        }
        
        for(int ind = 1;ind<coins.size();++ind)
        {
            for(int t=0;t<=amount;++t)
            {
                int nottake = dp[ind-1][t];
                int take = 1e9;
                if(coins[ind]<=t)
                    take = 1 + dp[ind][t-coins[ind]];
                dp[ind][t]=min(take,nottake);
            }
        }
        int ans = dp[coins.size()-1][amount];
        if(ans>=1e9)
            return -1;
        else
            return ans;
    }
};