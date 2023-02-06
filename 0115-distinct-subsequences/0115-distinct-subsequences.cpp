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
        // vector<vector<double>> dp(s.size()+1,vector<double>(t.size()+1,0));
        int n=s.size();
        int m=t.size();
        vector<double> dp(m+1,0);
        dp[0]=1;
        // return solution(s.size()-1,t.size()-1,s,t,dp);
        // for(int i=0;i<=n;++i)
        //     dp[i][0]=1;
        for(int i=1;i<=n;++i)
            for(int j=m;j>0;--j)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[j]=dp[j-1]+dp[j];
                }
                else
                {
                    dp[j]=dp[j];
                }
            }
        return (int)dp[t.size()];
    }
};