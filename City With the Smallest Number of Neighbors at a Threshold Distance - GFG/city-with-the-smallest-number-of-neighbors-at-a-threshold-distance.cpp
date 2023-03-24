//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> dijkstra(int src,int& n,vector<pair<int,int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> nodes;
        vector<int> distance(n,1e9);
        distance[src]=0;
        nodes.push({0,src});
        while(!nodes.empty())
        {
            int node = nodes.top().second;
            int steps = nodes.top().first;
            nodes.pop();
            for(auto it : adj[node])
            {
                int next = it.first;
                int cost = it.second;
                if(steps+cost<distance[next])
                {
                    distance[next]=steps+cost;
                    nodes.push({distance[next],next});
                }
            }
        }
        return distance;
    }
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) 
    {
        // vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();++i)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int city_no=-1,city_count=INT_MAX;
        for(int i=0;i<n;++i)
        {
            auto vec = dijkstra(i,n,adj);
            int count=0;
            for(auto it:vec)
            {
                if(it<=distanceThreshold)
                    count++;
            }
            if(count<=city_count)
            {
                city_count=count;
                city_no = i;
            }
        }
        return city_no;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends