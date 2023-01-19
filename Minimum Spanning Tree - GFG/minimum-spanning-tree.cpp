//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> nodes;
        int sum=0;
        nodes.push({0,0});
        vector<int> visited(V,0);
        while(!nodes.empty())
        {
            auto it = nodes.top();
            nodes.pop();
            int node = it.second;
            int wt = it.first;
            if(visited[node]==1)
                continue;
            visited[node]=1;
            sum+=wt;
            for(auto index:adj[node])
            {
                int adjnode = index[0];
                int weight = index[1];
                if(visited[adjnode]==0)
                    nodes.push({weight,adjnode});
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends