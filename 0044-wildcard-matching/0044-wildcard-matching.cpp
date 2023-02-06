class Solution {
public:
    bool solution(int index1,int index2,string& p,string& s,vector<vector<int>>& dp)
    {
        if(index1==0 && index2==0)
            return true;
        if(index1==0 && index2>0)
            return false;
        if(index2==0 && index1>0)
        {
            for(int i=1;i<=index1;++i)
            {
                if(p[i-1]!='*')
                    return false;
            }
            return true;
        }
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
            
        if(p[index1-1]==s[index2-1] || p[index1-1]=='?')
            return dp[index1][index2]=solution(index1-1,index2-1,p,s,dp);
        if(p[index1-1]=='*')
            return dp[index1][index2]=solution(index1-1,index2,p,s,dp)||solution(index1,index2-1,p,s,dp);
        return dp[index1][index2]=false;
    }
    bool isMatch(string s, string p) 
    {
        vector<vector<int>> dp(p.size()+1,vector<int>(s.size()+1,-1));
        return solution(p.size(),s.size(),p,s,dp);
    }
};