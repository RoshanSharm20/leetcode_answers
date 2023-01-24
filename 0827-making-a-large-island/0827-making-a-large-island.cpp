class disjointSet{
    public:
    vector<int> parent,size;
    disjointSet(int n)
    {
        parent.resize(n+1,0);
        size.resize(n+1);
        
        for(int i=0;i<=n;++i)
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
        if(ult_u==ult_v)
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
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        disjointSet ds(n*n);
        for(int row=0;row<n;++row)
        {
            for(int col=0;col<n;++col)
            {
                if(grid[row][col]==0)
                    continue;
                vector<int> delrow={0,-1,0,1};
                vector<int> delcol={-1,0,1,0};
                for(int i=0;i<4;++i)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        int cell = row*n+col;
                        int adjcell = nrow*n+ncol;
                        ds.unionBySize(cell,adjcell);
                    }
                }
            }
        }
        
        int max_size=0;
        for(int row=0;row<n;++row)
        {
            for(int col=0;col<n;++col)
            {
                if(grid[row][col]==1)
                    continue;
                vector<int> delrow={0,-1,0,1};
                vector<int> delcol={-1,0,1,0};
                set<int> components;
                for(int i=0;i<4;++i)
                {
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        int adjcell=nrow*n+ncol;
                        components.insert(ds.findUparent(adjcell));
                    }
                }
                int totalSize=0;
                for(auto it:components)
                {
                    totalSize+=ds.size[it];
                }
                max_size=max(max_size,totalSize+1);
            }
        }
        
        for(int cell = 0;cell<n*n;++cell)
        {
            max_size=max(max_size,ds.size[ds.findUparent(cell)]);
        }
        return max_size;
    }
};