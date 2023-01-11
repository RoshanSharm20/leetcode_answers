//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
        void Topo(int index,vector<pair<int,int>> adj[],vector<bool>& visited,stack<int>& st)
        {
            visited[index]=true;
            for(auto it:adj[index])
            {
                if(!visited[it.first])
                    Topo(it.first,adj,visited,st);
            }
            st.push(index);
        }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        vector<bool> visited(N,false);
        stack<int> st;
        for(int i=0;i<visited.size();++i)
        {
            if(!visited[i])
                Topo(i,adj,visited,st);
        }
        vector<int> dist(N,1e9);
        dist[0]=0;
        while(!st.empty())
        {
            int index = st.top();
            st.pop();
            for(auto it:adj[index])
            {
                int wt = it.second;
                int next = it.first;
                if(dist[index]+wt<dist[next])
                    dist[next]=dist[index]+wt;
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends