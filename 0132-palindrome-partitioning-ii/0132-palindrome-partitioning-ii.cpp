class Solution {
public:
    bool isPalindrome(string& temp)
    {
        int n=temp.size();
        int i=0;
        while(i<(n/2))
        {
            if(temp[i]!=temp[n-i-1])
                return false;
            i++;
        }
        return true;
    }
    int solution(int index,string& s,vector<int>& dp)
    {
        if(index==s.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        string temp="";
        int mini = INT_MAX;
        for(int i=index;i<s.size();++i)
        {
            temp+=s[i];
            if(isPalindrome(temp))
            {
                int cost = 1 + solution(i+1,s,dp);
                mini = min(cost,mini);
            }
        }
        return dp[index]=mini;
    }
    int minCut(string s) 
    {
        vector<int> dp(s.size(),-1);
        return solution(0,s,dp)-1;
    }
};