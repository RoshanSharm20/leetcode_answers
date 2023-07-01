//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solution(int index,int &x,int &y,int &z,vector<int> &dp)
    {
        if(index<0)
            return -1e9;
        if(index==0)
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
            
        int maxi=INT_MIN;
        maxi=max(maxi,1+solution(index-x,x,y,z,dp));
        maxi=max(maxi,1+solution(index-y,x,y,z,dp));
        maxi=max(maxi,1+solution(index-z,x,y,z,dp));
        return dp[index]=maxi;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        int ans = solution(n,x,y,z,dp);
        if(ans<=0)
            return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends