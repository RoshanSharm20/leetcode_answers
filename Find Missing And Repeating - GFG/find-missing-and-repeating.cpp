//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        unordered_map<int,int> nodes;
        for(int i=0;i<arr.size();++i)
        {
            nodes[arr[i]]+=1;
        }
        vector<int> ans;
        int twice=-1,missing=-1;
        for(int i=1;i<=n;++i)
        {
            if(nodes.find(i)!=nodes.end())
            {
                if(nodes[i]==2)
                    twice=i;
            }
            else
            {
                missing=i;
            }
        }
        ans.push_back(twice);
        ans.push_back(missing);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends