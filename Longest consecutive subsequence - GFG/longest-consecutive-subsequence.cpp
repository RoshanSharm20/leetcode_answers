//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int max_val=INT_MIN;
        for(int i=0;i<N;++i)
        {
            max_val=max(max_val,arr[i]);
        }
        vector<bool> ans(max_val+1,false);
        for(int i=0;i<N;++i)
            ans[arr[i]]=true;
        int count=0,max_count=0;
        for(int i=0;i<ans.size();++i)
        {
            if(ans[i]==true)
            {
                count++;
                max_count=max(max_count,count);
            }
            else
                count=0;
        }
        return max_count;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends