class Solution {
public:
    set<string> ans;
    int dp[46];
    int solution(int n)
    {
        if(n==0||n==1||n==2){
            return n;
        }
        else if(dp[n]!=-1){
            return dp[n];
        }
        else{
            return dp[n] = solution(n-1)+solution(n-2);
        }
    }
    int climbStairs(int n) 
    {
        // solution("",n);
        memset(dp,-1,sizeof(dp));
        return solution(n);
    }
};