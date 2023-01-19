class Solution {
public:
    vector<int> parent,size;
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
        if(ult_u==ult_v)
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
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        parent.resize(points.size());
        size.resize(points.size());
        for(int i=0;i<parent.size();++i)
        {
            parent[i]=i;
            size[i]=1;
        }
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<points.size();++i)
        {
            for(int j=0;j<points.size();++j)
            {
                if(i==j)
                    continue;
                int wt = (abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));
                edges.push_back({wt,{i,j}});
            }
        }
        int mst_sum=0;
        sort(edges.begin(),edges.end());
        for(auto it:edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(findUparent(u)!=findUparent(v))
            {
                mst_sum+=wt;
                unionBySize(u,v);
            }
        }
        return mst_sum;
    }
};