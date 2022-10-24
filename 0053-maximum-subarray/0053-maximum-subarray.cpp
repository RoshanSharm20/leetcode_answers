class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int curr_sum=nums[0],max_val=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            curr_sum=max(nums[i],curr_sum+nums[i]);
            max_val=max(max_val,curr_sum);
        }
        return max_val;
    }
};