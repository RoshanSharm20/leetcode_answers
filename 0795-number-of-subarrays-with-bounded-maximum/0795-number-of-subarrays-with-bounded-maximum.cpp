class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        int prevc=0,start=0,end=0,count=0;
        while(end<nums.size())
        {
            if(nums[end]>=left && nums[end]<=right)
            {
                prevc=end-start+1;
                count+=prevc;
            }
            else if(nums[end]<left)
            {
                count+=prevc;
            }
            else
            {
                start=end+1;
                prevc=0;
            }
            end++;
        }
        return count;
    }
};