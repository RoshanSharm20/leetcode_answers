//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
        map<char,int> nodes;
        int start=0,end=0,count=0,res=-1;
        while(end<s.size())
        {
            nodes[s[end]]+=1;
            if(nodes[s[end]]==1)
                count++;
            if(count<k)
                end++;
            else if(count==k)
            {
                res=max(res,end-start+1);
                end++;
            }
            else if(count>k)
            {
                while(count>k)
                {
                    nodes[s[start]]-=1;
                    if(nodes[s[start]]==0)
                        count--;
                    start++;
                }
                end++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends