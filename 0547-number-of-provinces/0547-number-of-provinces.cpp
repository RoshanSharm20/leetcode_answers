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
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        parent.resize(isConnected.size(),0);
        size.resize(isConnected.size(),0);
        for(int i=0;i<parent.size();++i)
        {
            parent[i]=i;
            size[i]=1;
        }
        
        for(int i=0;i<isConnected.size();++i)
        {
            for(int j=0;j<isConnected.size();++j)
            {
                if(isConnected[i][j]==1)
                {
                    unionBySize(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<parent.size();++i)
        {
            if(parent[i]==i)
                count++;
        }
        return count;
    }
};