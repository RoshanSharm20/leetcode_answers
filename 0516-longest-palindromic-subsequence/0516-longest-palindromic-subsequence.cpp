class Solution {
public:
    int solution(int index1,int index2,string& s,string& t,vector<vector<int>>& dp)
    {
        if(index1==0 || index2==0)
            return 0;
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        if(s[index1-1]==t[index2-1])
            return dp[index1][index2]=1+solution(index1-1,index2-1,s,t,dp);
        return dp[index1][index2]=max(solution(index1-1,index2,s,t,dp),solution(index1,index2-1,s,t,dp));
    }
    int longestPalindromeSubseq(string s) 
    {
        string t = s;
        reverse(t.begin(),t.end());
        // vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
        // return solution(s.size(),t.size(),s,t,dp);
        vector<int> prev(s.size()+1,0),curr(s.size()+1,0);
        for(int i=1;i<=s.size();++i)
        {
            for(int j=1;j<=t.size();++j)
            {
                if(s[i-1]==t[j-1])
                    curr[j]=1+prev[j-1];
                else
                    curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[t.size()];
    }
};