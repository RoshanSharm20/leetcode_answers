class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        map<int,int> nodes;
        for(int i=0;i<nums.size();++i)
        {
            nodes[nums[i]]+=1;
        }
        vector<int> ans;
        for(auto it:nodes)
        {
            if(it.second>1)
                ans.push_back(it.first);
        }
        return ans;
    }
};