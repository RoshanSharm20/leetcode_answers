//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class disjointSet{
    vector<int> parent,size;
    public:
        disjointSet(int n)
        {
            parent.resize(n,0);
            size.resize(n,0);
            for(int i=0;i<n;++i)
            {
                parent[i]=i;
                size[i]=1;
            }
        }
        
        int findUparent(int node)
        {
            if(parent[node]==node)
                return node;
            return parent[node]=findUparent(parent[node]);
        }
        
        void unionBySize(int a,int b)
        {
            int ult_u = findUparent(a);
            int ult_v = findUparent(b);
            if(ult_u == ult_v)
                return;
            if(size[ult_v]>size[ult_u])
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> visited(n,vector<int>(m,0));
        disjointSet ds(n*m);
        int count=0;
        vector<int> ans;
        for(auto it:operators)
        {
            int row = it[0];
            int col = it[1];
            if(visited[row][col]==1)
            {
                ans.push_back(count);
                continue;
            }
            
            visited[row][col]=1;
            count++;
            vector<int> delrow = {0,-1,0,1};
            vector<int> delcol = {-1,0,1,0};
            
            for(int i=0;i<4;++i)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    if(visited[nrow][ncol]==1)
                    {
                        int cell = row*m + col;
                        int adjcell = nrow*m + ncol;
                        if(ds.findUparent(cell)!=ds.findUparent(adjcell))
                        {
                            count--;
                            ds.unionBySize(cell,adjcell);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends