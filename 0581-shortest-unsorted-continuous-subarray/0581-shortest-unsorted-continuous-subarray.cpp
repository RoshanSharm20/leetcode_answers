class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int end = -1,max_val=nums[0];
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]<max_val)
                end = i;
            else
                max_val = nums[i];
        }
        
        int start = 0,min_val=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;--i)
        {
            if(nums[i]>min_val)
                start=i;
            else
                min_val = nums[i];
        }
        
        return end-start+1;
    }
};