class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans(2,-1);
        if(nums.size()==0)
            return ans;
        int start_index = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(start_index>nums.size()-1 || nums[start_index]!=target)
        {
            return ans;
        }
        
        int last_index = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        ans[0]=start_index;
        ans[1]=last_index-1;
        return ans;
    }
};