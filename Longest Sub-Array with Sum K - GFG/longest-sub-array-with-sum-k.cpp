//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // using the hashmap method
        map<int,int> nodes;
        int sum=0,res=0;
        for(int i=0;i<N;++i)
        {
            sum+=A[i];
            if(sum==K)
                res=max(res,i+1);
            if(nodes.find(sum-K)!=nodes.end())
            {
                res=max(res,i-nodes[sum-K]);
            }
            if(nodes.find(sum)==nodes.end())
            {
                nodes[sum]=i;
            }
        }
        return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends