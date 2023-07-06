//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int index,vector<int> adj[],vector<bool> &visited,vector<bool> &path)
    {
        visited[index]=true;
        path[index]=true;
        for(auto it:adj[index])
        {
            if(!visited[it])
            {
                if(dfs(it,adj,visited,path))
                    return true;
            }
            else if(path[it])
                return true;
        }
        path[index]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false),path(V,false);
        for(int i=0;i<V;++i)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited,path))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends