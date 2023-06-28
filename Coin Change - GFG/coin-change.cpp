//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solution(int index,int target,int coins[],vector<vector<long long>> &dp)
    {
        if(index==0)
        {
            if(target%coins[0]==0)
                return 1;
            return 0;
        }
        
        if(dp[index][target]!=-1)
            return dp[index][target];
            
        long long notpick = solution(index-1,target,coins,dp);
        long long pick =0;
        if(coins[index]<=target)
        {
            pick = solution(index,target-coins[index],coins,dp);
        }
        
        return dp[index][target]=pick+notpick;
    }
    long long int count(int coins[], int N, int sum) {

        vector<vector<long long>> dp(N,vector<long long>(sum+1,-1));
        return solution(N-1,sum,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends