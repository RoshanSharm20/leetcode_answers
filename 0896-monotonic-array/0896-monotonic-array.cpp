class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        bool all_increasing = true,all_decreasing=true;
        if(nums.size()==1)
            return true;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i-1]>nums[i])
                all_increasing=false;
            if(nums[i-1]<nums[i])
                all_decreasing=false;
        }
        
        if(all_increasing || all_decreasing)
            return true;
        return false;
    }
};