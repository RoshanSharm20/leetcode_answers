//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(string &temp)
    {
        int n=temp.size();
        
        for(int i=0;i<n/2;++i)
        {
            if(temp[i]!=temp[n-i-1])
                return false;
        }
        return true;
    }
    int solution(int index,string str,vector<int> &dp)
    {
        if(index==str.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int mini=1e9;
        string temp="";
        for(int k=index;k<str.size();++k)
        {
            temp+=str[k];
            if(check(temp))
            {
                mini=min(mini,1+solution(k+1,str,dp));
            }
        }
        return dp[index]=mini;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int> dp(n,-1);
        return solution(0,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends