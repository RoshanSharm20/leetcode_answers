class Solution {
public:
    int solution(int index,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(index==prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        if(buy)
        {
            return dp[index][buy]=max(-prices[index]+solution(index+1,0,prices,dp),solution(index+1,1,prices,dp));
        }
        else
        {
            return dp[index][buy]=max(solution(index+1,0,prices,dp),prices[index]+solution(index+1,1,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        // return solution(0,1,prices,dp);
        int n = prices.size();
        dp[n][0]=dp[n][1]=0;
        for(int index=n-1;index>=0;--index)
        {
            for(int buy=0;buy<=1;++buy)
            {
                if(buy)
                {
                    dp[index][buy]=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
                }
                else
                {
                    dp[index][buy]=max(dp[index+1][0],prices[index]+dp[index+1][1]);
                }
            }
        }
        return dp[0][1];
    }
};