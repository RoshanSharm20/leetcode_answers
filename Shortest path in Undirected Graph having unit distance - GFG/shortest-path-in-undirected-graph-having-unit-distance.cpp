//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i=0;i<edges.size();++i)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }
        queue<int> nodes;
        vector<int> distance(N,INT_MAX);
        nodes.push(src);
        distance[src]=0;
        while(!nodes.empty())
        {
            auto index= nodes.front();
            nodes.pop();
            for(auto it : adj[index])
            {
                if(distance[index]+1<distance[it])
                {
                    distance[it]=distance[index]+1;
                    nodes.push(it);
                }
            }
        }
        for(int i=0;i<distance.size();++i)
            if(distance[i]==INT_MAX)
                distance[i]=-1;
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends