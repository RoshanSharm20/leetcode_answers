class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int start = 0;
        int end = nums.size()-1;
        int last = nums.size()-1;
        while(start<end)
        {
            int mid = (start+end)/2;
            if(mid==0 || mid==last || (nums[mid]!=nums[mid-1]  && nums[mid]!=nums[mid+1]))
            {
                return nums[mid];
            }
            
            if((mid-0)%2==0 && (last-mid)%2==0)
            {
                if(nums[mid]==nums[mid-1])
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
            else if((mid-0)%2!=0 && (last-mid)%2!=0)
            {
                if(nums[mid]==nums[mid-1])
                {
                    start=mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
            else
            {
                if(nums[mid+1]==nums[mid])
                {
                   start=mid+1; 
                }
                else
                {
                    end = mid-1;
                }
            }
        }
        return nums[end];
    }
};