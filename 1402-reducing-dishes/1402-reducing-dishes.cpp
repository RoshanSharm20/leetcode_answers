class Solution {
public:
    int dp[501][501];
    int solution(int index,int time,vector<int> &satisfy)
    {
        if(index==satisfy.size())
            return 0;
        
        if(dp[index][time]!=-1)
            return dp[index][time];
        int pick=satisfy[index]*time + solution(index+1,time+1,satisfy);
        int notpick=solution(index+1,time,satisfy);
        
        return dp[index][time]=max(pick,notpick);
    }
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        sort(satisfaction.begin(),satisfaction.end());
        memset(dp,-1,sizeof(dp));
        return max(0,solution(0,1,satisfaction));
    }
};