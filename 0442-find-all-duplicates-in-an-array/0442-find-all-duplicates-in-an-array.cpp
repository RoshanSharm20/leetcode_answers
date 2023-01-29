class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> nodes(nums.size()+1,0);
        for(int i=0;i<nums.size();++i)
        {
            nodes[nums[i]]++;
        }
        vector<int> ans;
        for(int i=1;i<nodes.size();++i)
            if(nodes[i]>1)
                ans.push_back(i);
        return ans;
    }
};