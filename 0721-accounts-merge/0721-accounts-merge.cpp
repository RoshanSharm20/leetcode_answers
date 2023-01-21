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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        parent.resize(accounts.size(),0);
        size.resize(accounts.size(),0);
        for(int i=0;i<parent.size();++i)
        {
            parent[i]=i;
            size[i]=1;
        }
        map<string,int> mailMapping;
        for(int i=0;i<accounts.size();++i)
        {
            for(int j=1;j<accounts[i].size();++j)
            {
                if(mailMapping.find(accounts[i][j])==mailMapping.end())
                {
                    mailMapping[accounts[i][j]]=i;
                }
                else
                    unionBySize(i,mailMapping[accounts[i][j]]);
            }
        }
        vector<vector<string>> ans;
        vector<string> mails[accounts.size()];
        for(auto it:mailMapping)
        {
            string mail=it.first;
            int index = findUparent(it.second);
            mails[index].push_back(mail);
        }
        
        for(int i=0;i<accounts.size();++i)
        {
            vector<string> temp;
            if(mails[i].size()>0)
            {
                temp.push_back(accounts[i][0]);
                for(auto it:mails[i])
                    temp.push_back(it);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};