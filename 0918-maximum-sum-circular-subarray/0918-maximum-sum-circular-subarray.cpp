class Solution {
public:
    int kadaneAlgo(vector<int>& nums)
    {
        int max_val=nums[0],curr_max=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            curr_max =max(curr_max+nums[i],nums[i]);
            max_val = max(max_val,curr_max);
        }
        return max_val;
    }
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int normal_max = kadaneAlgo(nums);
        int total_sum = 0;
        bool allfalse=true;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>0)
                allfalse=false;
            total_sum+=nums[i];
            nums[i]=-nums[i];
        }
        int circular_max = total_sum+kadaneAlgo(nums);
        if(allfalse)
            return normal_max;
        return max(circular_max,normal_max);
    }
};