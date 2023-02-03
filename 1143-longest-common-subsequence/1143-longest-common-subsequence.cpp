class Solution {
public:
    int solution(int index1,int index2,string& text1,string& text2,vector<vector<int>>& dp)
    {
        if(index1==0 || index2==0)
            return 0;
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        if(text1[index1-1]==text2[index2-1])
            return dp[index1][index2]=1+solution(index1-1,index2-1,text1,text2,dp);
        return dp[index1][index2]=max(solution(index1-1,index2,text1,text2,dp),solution(index1,index2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solution(text1.size(),text2.size(),text1,text2,dp);
    }
};