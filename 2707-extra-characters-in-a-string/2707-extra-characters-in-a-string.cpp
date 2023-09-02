class Solution {
public:
    int dp[10005];
    int solution(int index,string &s,unordered_set<string> &valid)
    {
        if(index==0)
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        int ans=index;
        string st="";
        for(int i=index;i>=1;--i)
        {
            st=s[i-1]+st;
            if(valid.find(st)==valid.end())
            {
                ans=min(ans,(index-i+1)+solution(i-1,s,valid));
            }
            else
            {
                ans=min(ans,solution(i-1,s,valid));
            }
        }
        
        return dp[index]=ans;
        
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        unordered_set<string> valid;
        for(auto it:dictionary)
            valid.insert(it);
        memset(dp,-1,sizeof(dp));
        return solution(s.size(),s,valid);
        
    }
};