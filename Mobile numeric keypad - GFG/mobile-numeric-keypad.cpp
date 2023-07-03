//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long solution(int row,int col,int n,vector<vector<int>> &mat,vector<vector<long long>> &dp)
	{
        if(n==1)
            return 1;
        if(dp[mat[row][col]][n]!=-1)
            return dp[mat[row][col]][n];
        long long a,b,c,d,e;
	    a = b=c=d=e=0;
	    a=solution(row,col,n-1,mat,dp);
	    if(col-1>=0 && mat[row][col-1]!=-1)
	        b=solution(row,col-1,n-1,mat,dp);
	    if(row-1>=0 && mat[row-1][col]!=-1)
	        c=solution(row-1,col,n-1,mat,dp);
	    if(col+1<3 && mat[row][col+1]!=-1)
	        d=solution(row,col+1,n-1,mat,dp);
	    if(row+1<4 && mat[row+1][col]!=-1)
	        e=solution(row+1,col,n-1,mat,dp);
	        
	    long long total=a+b+c+d+e;
	    
	    return dp[mat[row][col]][n]=total;
	}
	long long getCount(int N)
	{
	    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
	    vector<vector<long long>> dp(10,vector<long long>(N+1,-1));
	    long long ans=0;
	    for(int i=0;i<4;++i)
	    {
	        for(int j=0;j<3;++j)
	        {
	            if(mat[i][j]==-1)
	                continue;
	            ans+=solution(i,j,N,mat,dp);
	        }
	    }
	    return ans;
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends