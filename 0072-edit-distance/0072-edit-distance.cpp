class Solution {
public:
    int solution(int index1,int index2,string& word1,string& word2,vector<vector<int>>& dp)
    {
        if(index1==0)
            return index2;
        if(index2==0)
            return index1;
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        
        if(word1[index1-1]==word2[index2-1])
            return dp[index1][index2]=solution(index1-1,index2-1,word1,word2,dp);
        else
        {
            return dp[index1][index2]=1+ min(solution(index1,index2-1,word1,word2,dp),
                          min(solution(index1-1,index2,word1,word2,dp),
                              solution(index1-1,index2-1,word1,word2,dp)));
        }
    }
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        // return solution(word1.size(),word2.size(),word1,word2,dp);
        for(int i=0;i<=word2.size();++i)
            dp[0][i]=i;
        for(int i=0;i<=word1.size();++i)
            dp[i][0]=i;
        
        for(int index1=1;index1<=word1.size();++index1)
        {
            for(int index2=1;index2<=word2.size();++index2)
            {
                if(word1[index1-1]==word2[index2-1])
                    dp[index1][index2]=dp[index1-1][index2-1];
                else
                {
                    dp[index1][index2]=1+ min(dp[index1][index2-1],
                                  min(dp[index1-1][index2],
                                      dp[index1-1][index2-1]));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};