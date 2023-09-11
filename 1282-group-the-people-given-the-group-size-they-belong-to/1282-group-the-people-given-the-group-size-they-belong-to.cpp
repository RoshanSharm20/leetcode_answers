class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        map<int,vector<int>> nums;
        for(int i=0;i<groupSizes.size();++i)
            nums[groupSizes[i]].push_back(i);
        vector<vector<int>> ans;
        for(auto it:nums)
        {
            int limit = it.first;
            int size = it.second.size();
            auto vec = it.second;
            vector<int> temp;
            for(int i=0;i<size;++i)
            {
                if(temp.size()==limit)
                {
                    ans.push_back(temp);
                    temp.clear();
                    temp.push_back(vec[i]);
                }
                else
                {
                    temp.push_back(vec[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};