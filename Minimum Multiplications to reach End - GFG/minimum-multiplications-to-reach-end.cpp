//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 100000;
        vector<int> steps_taken(100000,INT_MAX);
        steps_taken[start]=0;
        queue<pair<int,int>> nodes;
        nodes.push({0,start});
        while(!nodes.empty())
        {
            auto it = nodes.front();
            int nums = it.second;
            int steps = it.first;
            nodes.pop();
            for(auto i:arr)
            {
                int number = (nums*i)%mod;
                if(steps+1<steps_taken[number])
                {
                    steps_taken[number]=steps+1;
                    if(number==end)
                        return steps_taken[number];
                    nodes.push({steps_taken[number],number});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends