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
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // return solution(text1.size(),text2.size(),text1,text2,dp);
        for(int i=0;i<=text1.size();++i)
            dp[i][0]=0;
        for(int i=0;i<=text2.size();++i)
            dp[0][1]=0;
        for(int i=1;i<=text1.size();++i)
        {
            for(int j=1;j<=text2.size();++j)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string st = "";
        for(int i=0;i<dp[text1.size()][text2.size()];++i)
        {
            st+='$';
        }
        int index = dp[text1.size()][text2.size()]-1;
        int i = text1.size(),j=text2.size();
        while(i>0 && j>0)
        {
            if(text1[i-1]==text2[j-1])
            {
                st[index]=text1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        cout<<st<<endl;
        return dp[text1.size()][text2.size()];
    }
};