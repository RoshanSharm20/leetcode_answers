class Solution {
public:
    int dp[1001][2002];
    int solution(int index,int prev,vector<vector<int>>& pairs)
    {
        if(index==0)
        {
            if(pairs[index][1]<prev)
                return 1;
            else
                return 0;
        }
        
        if(dp[index][prev+1000]!=-1)
            return dp[index][prev+1000];
        int nottake = solution(index-1,prev,pairs);
        int take =0;
        if(pairs[index][1]<prev)
            take = 1+ solution(index-1,pairs[index][0],pairs);
        return dp[index][prev+1000]=max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        return solution(pairs.size()-1,1001,pairs);
    }
};