//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint_set
{
    vector<int> size,parent;
    public:
    Disjoint_set(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;++i)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
        
    int findUparent(int node)
    {
            if(node==parent[node])
                return node;
            return parent[node]=findUparent(parent[node]);
    }
        
    void unionBySize(int u,int v)
    {
            int ult_u = findUparent(u);
            int ult_v = findUparent(v);
            if(ult_u == ult_v)
                return;
            if(size[ult_u]<size[ult_v])
            {
                parent[ult_u]=ult_v;
                size[ult_v]+=size[ult_u];
            }
            else
            {
                parent[ult_v]=ult_u;
                size[ult_u]+=size[ult_v];
            }
    }
};
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;++i)
        {
            for(auto it:adj[i])
            {
                int u=i;
                int v=it[0];
                int w=it[1];
                edges.push_back({w,{u,v}});
            }
        }
        Disjoint_set ds(V);
        sort(edges.begin(),edges.end());
        int wt_sum=0;
        for(auto it:edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUparent(u)!=ds.findUparent(v))
            {
                wt_sum+=wt;
                ds.unionBySize(u,v);
            }
        }
    return wt_sum;
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