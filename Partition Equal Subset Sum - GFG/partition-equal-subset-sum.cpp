//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solution(int index,int target,vector<vector<int>> &dp,int arr[])
    {
        if(target==0)
            return true;
        if(index==0)
            return arr[0]==target;
        
        if(dp[index][target]!=-1)
            return dp[index][target];
        bool pick=false,notpick=false;
        notpick = solution(index-1,target,dp,arr);
        if(target>=arr[index])
            pick = solution(index-1,target-arr[index],dp,arr);
        
        return dp[index][target]=pick|notpick;
    }
    int equalPartition(int N, int arr[])
    {
        int total=0;
        for(int i=0;i<N;++i)
            total+=arr[i];
        if(total%2)
            return 0;
        int target=total/2;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return solution(N-1,target,dp,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends