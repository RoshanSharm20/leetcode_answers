class Solution {
public:
    int solution(int i,int j,vector<int>& piles,vector<vector<int>>& dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int max_val = INT_MIN;
        max_val=max(max_val,piles[i]+max(solution(i+1,j-1,piles,dp),solution(i+2,j,piles,dp)));
        max_val=max(max_val,piles[j]+max(solution(i+1,j-1,piles,dp),solution(i,j-2,piles,dp)));
        return dp[i][j]=max_val;
            
    }
    bool stoneGame(vector<int>& piles) 
    {
        int n = piles.size();
        int sum = accumulate(piles.begin(),piles.end(),0);
        vector<vector<int>> dp(n,vector<int>(n,-1));
        solution(0,n-1,piles,dp);
        return (dp[0][n-1]>(sum/2));
    }
};