class Solution {
public:
    bool solution(int index1,int index2,int index3,string &s1,string &s2,string &s3,vector<vector<vector<int>>> &dp)
    {
        if(index3==0)
            return true;
        
        if(dp[index1][index2][index3]!=-1)
            return dp[index1][index2][index3];
        
        bool first=false,second=false;
        
        if(index1>0 && s1[index1-1]==s3[index3-1])
            first = solution(index1-1,index2,index3-1,s1,s2,s3,dp);
        
        if(index2>0 && s2[index2-1]==s3[index3-1])
            second = solution(index1,index2-1,index3-1,s1,s2,s3,dp);
        
        return dp[index1][index2][index3]=first|second;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return solution(s1.size(),s2.size(),s3.size(),s1,s2,s3,dp);
    }
};