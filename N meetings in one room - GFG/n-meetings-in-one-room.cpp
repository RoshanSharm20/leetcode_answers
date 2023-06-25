//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool mycomp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
    {
        if(a.first.second<b.first.second)
            return true;
        else if(a.first.second==b.first.second)
        {
            if(a.second<b.second)
                return true;
            return false;
        }
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
       int count=1;
       vector<pair<pair<int,int>,int>> nodes;
       for(int i=0;i<n;++i)
       {
           nodes.push_back({{start[i],end[i]},i+1});
       }
       sort(nodes.begin(),nodes.end(),mycomp);
       int endtime=nodes[0].first.second;
       for(int i=1;i<n;++i)
       {
           if(nodes[i].first.first>endtime)
           {
               count++;
               endtime=nodes[i].first.second;
           }
       }
       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends