class Solution {
public:
    int solution(int i,int j,vector<int>& cuts,vector<vector<int>>& dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini = 1e9;
        for(int k=i;k<=j;++k)
        {
            int steps = cuts[j+1]-cuts[i-1]+solution(i,k-1,cuts,dp)+solution(k+1,j,cuts,dp);
            mini = min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) 
    {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int x = cuts.size();
        vector<vector<int>> dp(x,vector<int>(x,0));
        // return solution(1,x-2,cuts,dp);
        for(int i=x-2;i>=1;--i)
        {
            for(int j=i;j<x-1;++j)
            {
                int mini = 1e9;
                for(int k=i;k<=j;++k)
                {
                    int steps = cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini = min(mini,steps);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][x-2];
    }
};