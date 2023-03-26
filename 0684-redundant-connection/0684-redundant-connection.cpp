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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        Disjoint_Set ds(n);
        vector<int> ans;
        for(int i=0;i<n;++i)
        {
            int first = edges[i][0];
            int second = edges[i][1];
            if(ds.findParent(first)!=ds.findParent(second))
                ds.unionBySize(first,second);
            else
            {
                ans=edges[i];
            }
        }
        return ans;
    }
};