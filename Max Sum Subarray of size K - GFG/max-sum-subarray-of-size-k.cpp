//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long sum=0,start=0,end=0,max_val=INT_MIN;
        while(end<N)
        {
            sum+=Arr[end];
            if(end-start+1<K)
                end++;
            else
            {
                max_val = max(max_val,sum);
                sum-=Arr[start];
                start++;
                end++;
            }
        }
        return max_val;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends