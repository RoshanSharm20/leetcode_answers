class Solution {
public:
    int solution(int index,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(index>=prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        if(buy)
        {
            return dp[index][buy]=max(-prices[index]+solution(index+1,0,prices,dp),solution(index+1,buy,prices,dp));
        }
        else
        {
            return dp[index][buy]=max(prices[index]+solution(index+2,1,prices,dp),solution(index+1,buy,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        // return solution(0,1,prices,dp);
        for(int index=n-1;index>=0;--index)
        {
            dp[index][1]=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
            dp[index][0]=max(prices[index]+dp[index+2][1],dp[index+1][0]);
        }
        return dp[0][1];
    }
};