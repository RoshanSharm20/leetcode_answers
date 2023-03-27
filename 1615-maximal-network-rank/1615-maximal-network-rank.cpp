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
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        vector<int> adj[n];
        // Disjoint_Set ds(n);
        for(int i=0;i<roads.size();++i)
        {
            int first = roads[i][0];
            int second = roads[i][1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        
        int max_val=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i!=j)
                {
                    int count=0;
                    if(find(adj[i].begin(),adj[i].end(),j)!=adj[i].end())
                        count=adj[i].size()+adj[j].size()-1;
                    else
                        count=adj[i].size()+adj[j].size();
                    max_val = max(max_val,count);
                }
            }
        }
        return max_val;
    }
};