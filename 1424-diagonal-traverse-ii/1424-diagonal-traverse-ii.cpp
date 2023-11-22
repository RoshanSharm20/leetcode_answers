class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
       vector<int> ans;
    map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> nodes;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=0;j<nums[i].size();++j)
            {
                nodes[(i+j)].push({j,nums[i][j]});
            }
        }
        
        for(auto it:nodes)
        {
            auto x = it.second;
            while(!x.empty())
            {
                ans.push_back(x.top().second);
                x.pop();
            }
        }
        return ans;
    }
};