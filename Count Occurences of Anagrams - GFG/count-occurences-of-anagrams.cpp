//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
        int n = pat.size();
        int start=0,end=0,count=0,ans=0;
        map<char,int> nodes;
        for(int i=0;i<pat.size();++i)
        {
            nodes[pat[i]]+=1;
        }
        count=nodes.size();
        while(end<txt.size())
        {
            if(nodes.find(txt[end])!=nodes.end())
            {
                nodes[txt[end]]-=1;
                if(nodes[txt[end]]==0)
                    count--;
            }
            
            if(end-start+1<n)
                end++;
            else
            {
                if(count==0)
                    ans++;
                if(nodes.find(txt[start])!=nodes.end())
                {
                   nodes[txt[start]]+=1;
                   if(nodes[txt[start]]==1)
                        count++;
                }
                start++;
                end++;
            }
        }
        return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends