class Solution {
public:
    bool solution(int index,string &s,set<string> &st,vector<int> &dp)
    {
        if(index==s.size())
            return true;
        if(dp[index]!=-1)
            return dp[index];
        string temp="";
        bool possible=false;
        for(int k=index;k<s.size();++k)
        {
            temp+=s[k];
            if(st.find(temp)!=st.end())
            {
                possible = possible | solution(k+1,s,st,dp);
            }
        }
        return dp[index]=possible;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        set<string> st;
        for(int i=0;i<wordDict.size();++i)
            st.insert(wordDict[i]);
        int n = s.size();
        vector<int> dp(n,-1);
        return solution(0,s,st,dp);
    }
};