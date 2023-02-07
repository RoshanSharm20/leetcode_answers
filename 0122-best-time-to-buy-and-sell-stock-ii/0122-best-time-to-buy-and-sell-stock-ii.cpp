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
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solution(0,1,prices,dp);
    }
};