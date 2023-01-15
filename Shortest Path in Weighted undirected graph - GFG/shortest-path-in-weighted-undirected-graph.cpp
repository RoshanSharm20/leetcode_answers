//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<edges.size();++i)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> nodes;
        nodes.push({0,1});
        vector<int> distance(n+1,INT_MAX);
        distance[1]=0;
        vector<int> parent(n+1,0);
        for(int i=1;i<=n;++i)
            parent[i]=i;
        while(!nodes.empty())
        {
            auto it = nodes.top();
            int dis = it.first;
            int node = it.second;
            nodes.pop();
            for(auto adj_node:adj[node])
            {
                int vertex = adj_node.first;
                int weight = adj_node.second;
                if(dis+weight<distance[vertex])
                {
                    distance[vertex]=dis+weight;
                    nodes.push({distance[vertex],vertex});
                    parent[vertex]=node;
                }
            }
        }
        
        if(distance[n]==INT_MAX)
            return {-1};
        int nod = n;
        vector<int> seq;
        while(parent[nod]!=nod)
        {
            seq.push_back(nod);
            nod=parent[nod];
        }
        seq.push_back(1);
        reverse(seq.begin(),seq.end());
        return seq;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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