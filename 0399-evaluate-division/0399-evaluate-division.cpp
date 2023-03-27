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
    double bfs(int first,int second,int& size,vector<pair<int,double>> adj[])
    {
        vector<double> distance(size,DBL_MAX);
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> nodes;
        nodes.push({1.00000,first});
        distance[first]=1.00000;
        while(!nodes.empty())
        {
            double cost = nodes.top().first;
            int node = nodes.top().second;
            nodes.pop();
            if(node==second)
                return cost;
            for(auto it : adj[node])
            {
                int next = it.first;
                double weight = it.second;
                if(weight*cost<distance[next])
                {
                    distance[next]=weight*cost;
                    nodes.push({distance[next],next});
                }
            }
        }
        return 1.00000;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        // Disjoint_Set ds(50);
        unordered_map<string,int> available;
        // int n = equations.size();
        int count=0;
        for(int i=0;i<equations.size();++i)
        {
            string first = equations[i][0];
            string second = equations[i][1];
            if(available.find(first)==available.end())
            {
                available[first]=count;
                count++;
            }
            if(available.find(second)==available.end())
            {
                available[second]=count;
                count++;
            }
        }
        
        Disjoint_Set ds(count);
        
        vector<pair<int,double>> adj[count];
        for(int i=0;i<equations.size();++i)
        {
            int first = available[equations[i][0]];
            int second = available[equations[i][1]];
            ds.unionBySize(first,second);
            double cost = values[i];
            adj[first].push_back({second,cost});
            adj[second].push_back({first,(1.00000/cost)});
        }
        
        vector<double> ans;
        for(int i=0;i<queries.size();++i)
        {
            if((available.find(queries[i][0])==available.end())||(available.find(queries[i][1])==available.end()))
            {
                ans.push_back(-1.00000);
                continue;
            }
            
            int first = available[queries[i][0]];
            int second = available[queries[i][1]];
            if(ds.findParent(first)!=ds.findParent(second))
            {
                ans.push_back(-1.00000);
                continue;
            }
            
            double value = bfs(first,second,count,adj);
            ans.push_back(value);
        }
        return ans;
    }
};