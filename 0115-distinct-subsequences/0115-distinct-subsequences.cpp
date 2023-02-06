class Solution {
public:
    int solution(int index1,int index2,string& s,string& t,vector<vector<int>>& dp)
    {
        if(index2<0)
            return 1;
        if(index1<0)
            return 0;
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        if(s[index1]==t[index2])
        {
            return dp[index1][index2]=solution(index1-1,index2-1,s,t,dp)+solution(index1-1,index2,s,t,dp);
        }
        else
        {
            return dp[index1][index2]=solution(index1-1,index2,s,t,dp);
        }
    }
    int numDistinct(string s, string t) 
    {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return solution(s.size()-1,t.size()-1,s,t,dp);
    }
};