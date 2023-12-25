class Solution {
public:
    int solution(int index,string &s,vector<int> &dp)
    {
        if(index==s.size())
            return 1;
        if(s[index]=='0')
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        int one=0,two=0;
        one = solution(index+1,s,dp);
        if(index!=s.size()-1)
        {
            string sub;
            sub = s[index];
            sub+=s[index+1];
            int num = stoi(sub);
            if(num<=26)
                two=solution(index+2,s,dp);
        }
        
        return dp[index]=one+two;
    }
    int numDecodings(string s) 
    {
        int n = s.size();
        vector<int> dp(n,-1);
        return solution(0,s,dp);
    }
};