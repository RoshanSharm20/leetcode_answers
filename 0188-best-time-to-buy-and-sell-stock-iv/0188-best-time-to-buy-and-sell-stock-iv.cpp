class Solution {
public:
    int solution(int index,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(cap==0 || index==prices.size())
            return 0;
        if(dp[index][buy][cap]!=-1)
            return dp[index][buy][cap];
        if(buy)
        {
            return dp[index][buy][cap]=max(-prices[index]+solution(index+1,0,cap,prices,dp),solution(index+1,buy,cap,prices,dp));
        }
        else
        {
            return dp[index][buy][cap]=max(prices[index]+solution(index+1,1,cap-1,prices,dp),solution(index+1,buy,cap,prices,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // return solution(0,1,k,prices,dp);
        int n=prices.size();
        for(int index=n-1;index>=0;--index)
        {
            for(int buy=0;buy<=1;++buy)
            {
                for(int cap=1;cap<=k;++cap)
                {
                    if(buy)
                    {
                        dp[index][buy][cap]=max(-prices[index]+dp[index+1][0][cap],dp[index+1][buy][cap]);
                    }
                    else
                    {
                        dp[index][buy][cap]=max(prices[index]+dp[index+1][1][cap-1],dp[index+1][buy][cap]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};

// class Solution {
// public:
//     int solution(int index,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp)
//     {
//         if(cap==0 || index==prices.size())
//             return 0;
//         if(dp[index][buy][cap]!=-1)
//             return dp[index][buy][cap];
//         if(buy)
//         {
//             return dp[index][buy][cap]=max(-prices[index]+solution(index+1,0,cap,prices,dp),solution(index+1,buy,cap,prices,dp));
//         }
//         else
//         {
//             return dp[index][buy][cap]=max(prices[index]+solution(index+1,1,cap-1,prices,dp),solution(index+1,buy,cap,prices,dp));
//         }
//     }
//     int maxProfit(vector<int>& prices) 
//     {
//         vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
//         return solution(0,1,2,prices,dp);
//     }
// };