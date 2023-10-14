class Solution {
public:
    int solution(int index,int remaining,vector<int> &cost,vector<int> &time,vector<vector<int>> &dp)
    {
        if(remaining<=0)
            return 0;
        
        if(index>=cost.size())
            return 1e9;
        
        if(dp[index][remaining]!=-1)
            return dp[index][remaining];
        
        int take = cost[index]+solution(index+1,remaining-1-time[index],cost,time,dp);
        
        int nottake = solution(index+1,remaining,cost,time,dp);
        
        return dp[index][remaining]=min(take,nottake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        int n = cost.size();
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        
        return solution(0,n,cost,time,dp);
    }
};