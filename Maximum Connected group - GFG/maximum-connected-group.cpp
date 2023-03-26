//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Disjoint_Set{
	
public:
    vector<int> rank,parent,size;
	Disjoint_Set(int n)
	{
		rank.resize(n+1,0);
		size.resize(n+1,1);
		parent.resize(n+1);
		for(int i=0;i<=n;++i)
		{
			parent[i]=i;
		}
	}

	int findParent(int u)
	{
		if(u==parent[u])
			return u;
		return parent[u]=findParent(parent[u]);
	}
	void unionByRank(int u,int v)
	{
		int ult_u = findParent(u);
		int ult_v = findParent(v);
		if(ult_u==ult_v)
			return;
		if(rank[ult_u]<rank[ult_v])
		{
			parent[ult_u]=ult_v;
		}
		else if(rank[ult_u]>rank[ult_v])
		{
			parent[ult_v]=ult_u;
		}
		else
		{
			parent[ult_v]=ult_u;
			rank[ult_u]++;
		}
	}

	void unionBySize(int u,int v)
	{
		int ult_u = findParent(u);
		int ult_v = findParent(v);
		if(parent[ult_u]==parent[ult_v])
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
class Solution {
  public:
    bool isValid(int nrow,int ncol,int n)
    {
        if((nrow>=0 && nrow<n && ncol>=0 && ncol<n))
            return true;
        return false;
    }
    int MaxConnection(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        Disjoint_Set ds(n*n);
        // vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    for(int k=0;k<4;++k)
                    {
                        int nrow = i+ delrow[k];
                        int ncol = j+ delcol[k];
                        if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1)
                        {
                            int node = i*n + j;
                            int adjnode = nrow*n + ncol;
                            if(ds.findParent(node)!=ds.findParent(adjnode))
                                ds.unionBySize(node,adjnode);
                        }
                    }
                }
            }
        }
        
        int max_val=*max_element(ds.size.begin(),ds.size.end());
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==0)
                {
                   set<int> p;
                   for(int k=0;k<4;++k)
                   {
                       int nrow = i+delrow[k];
                       int ncol = j+delcol[k];
                       if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1)
                       {
                           int adjnode = nrow*n + ncol;
                           p.insert(ds.findParent(adjnode));
                       }
                   }
                   int maxi = 1;
                   for(auto it:p)
                   {
                       maxi+=ds.size[it];
                   }
                   max_val = max(maxi,max_val);
                }
            }
        }
        return max_val;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends