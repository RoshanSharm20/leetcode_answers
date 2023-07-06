class Solution {
public:
    bool blackBox(vector<int>& nums,int target,int size)
    {
        int sum=0;
        for(int i=0;i<size;++i)
            sum+=nums[i];
        int max_val = sum;
        int left=0,right=size-1;
        while(right!=nums.size()-1)
        {
            sum-=nums[left];
            left++;
            right++;
            sum+=nums[right];
            max_val=max(max_val,sum);
        }
        return max_val>=target;
    }
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int low = 1,high = nums.size()+1;
        bool isPossible=false;
        while(low<high)
        {
            int mid = (low+high)/2;
            if(blackBox(nums,target,mid))
            {
                high=mid;
                isPossible=true;
            }
            else
            {
                low=mid+1;
            }
        }    
        if(isPossible)
            return low;
        return 0;
    }
};