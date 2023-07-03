//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solution(int i,int j,string &s,string &t,vector<vector<int>> &dp)
    {
        if(i==0)
            return j;
        if(j==0)
            return i;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i-1]==t[j-1])
            return dp[i][j]=solution(i-1,j-1,s,t,dp);
        else
        {
            int in = 1 + solution(i,j-1,s,t,dp);
            int del=1+solution(i-1,j,s,t,dp);
            int rep=1+solution(i-1,j-1,s,t,dp);
            return dp[i][j]=min(in,min(del,rep));
        }
    }
    int editDistance(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solution(s.size(),t.size(),s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends