class Disjoint_Set{
	vector<int> rank,parent,size;
public:
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
    int regionsBySlashes(vector<string>& grid) 
    {
        int n = grid.size()+1;
        Disjoint_Set ds(n*n);
        //get all the boundary nodes connected
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==0 || i==n-1 || j==0 || j==n-1)
                {
                    int node = i*n + j;
                    if(node!=0)
                        ds.unionBySize(0,node);
                }
            }
        }
        int count=1;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid.size();++j)
            {
                if(grid[i][j]=='/')
                {
                    int first = (i+1)*n + j;
                    int second = (i)*n + (j+1);
                    if(ds.findParent(first)!=ds.findParent(second))
                        ds.unionBySize(first,second);
                    else
                        count++;
                }
                else if(grid[i][j]=='\\')
                {
                    int first = (i)*n + j;
                    int second = (i+1)*n + (j+1);
                    if(ds.findParent(first)!=ds.findParent(second))
                        ds.unionBySize(first,second);
                    else
                        count++;
                }
            }
        }
        return count;
    }
};