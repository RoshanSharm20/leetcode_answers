//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solution(int row,int col,int N,vector<vector<int>> &Matrix,vector<vector<int>> &dp)
    {
        if(col<0 || col>=N)
            return -1e8;
        if(row==0)
            return dp[row][col]=Matrix[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int maxi=0;
        for(int i=-1;i<=1;++i)
        {
            int value = solution(row-1,col+i,N,Matrix,dp);
            maxi=max(maxi,Matrix[row][col]+value);
        }
        
        return dp[row][col]=maxi;
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        int maxi=0;
        for(int i=0;i<N;++i)
        {
            maxi=max(maxi,solution(N-1,i,N,Matrix,dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends