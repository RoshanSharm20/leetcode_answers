class Solution {
public:
    vector<int> parent,size;
    int findUparent(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node]=findUparent(parent[node]);
    }
    
    void unionBySize(int a,int b)
    {
        int ult_u=findUparent(a);
        int ult_v=findUparent(b);
        if(ult_v==ult_u)
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
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        parent.resize(n,0);
        size.resize(n,0);
        for(int i=0;i<parent.size();++i)
        {
            parent[i]=i;
            size[i]=1;
        }
        int countextra=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(findUparent(u)!=findUparent(v))
            {
                unionBySize(u,v);
            }
            else
                countextra++;
        }
        
        int count=0;
        for(int i=0;i<parent.size();++i)
        {
            if(parent[i]==i)
                count++;
        }
        
        if(countextra>=count-1)
            return count-1;
        else
            return -1;
    }
};