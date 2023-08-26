class Solution {
public:
    int solution(int floor,int eggs,vector<vector<int>> &dp)
    {
        if(floor==0 || floor==1)
            return floor;
        if(eggs==1)
            return floor;
        
        if(dp[floor][eggs]!=-1)
            return dp[floor][eggs];
        
        int mini = INT_MAX;
        for(int k=1;k<=floor;++k)
        {
            int temp = 1 + max(solution(k-1,eggs-1,dp),solution(floor-k,eggs,dp));
            mini = min(mini,temp);
        }
        
        return dp[floor][eggs]=mini;
    }
    int twoEggDrop(int n) 
    {
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return solution(n,2,dp);
    }
};