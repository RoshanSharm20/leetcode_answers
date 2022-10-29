class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        map<vector<int>,int> ans;
        int count=0;
        for(int i=0;i<grid.size();++i)
        {
            vector<int> v;
            for(int j=0;j<grid.size();++j)
                v.push_back(grid[j][i]);
            if(ans.find(v)!=ans.end())
                ans[v]++;
            else
                ans[v]=1;
        }
        for(int i=0;i<grid.size();++i)
        {
            if(ans.find(grid[i])!=ans.end())
                count+=ans[grid[i]];
        }  
        return count;
    }
};