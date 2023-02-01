class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        vector<vector<int>> ans(2);
        map<int,int> nodes;
        for(auto it:matches)
        {
            if(nodes.find(it[0])==nodes.end())
            {
                nodes[it[0]]=0;
            }
            nodes[it[1]]-=1;
        }
        
        for(auto it:nodes)
        {
            if(it.second==0)
                ans[0].push_back(it.first);
            if(it.second==-1)
                ans[1].push_back(it.first);
        }
        return ans;
    }
};