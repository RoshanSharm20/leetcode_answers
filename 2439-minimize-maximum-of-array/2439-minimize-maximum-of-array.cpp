class Solution {
public:
    bool isPossible(long long int mid,vector<int>& nums)
    {
        long long int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            if(sum>((i+1)*mid))
                return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) 
    {
        long long int low = *min_element(nums.begin(),nums.end());
        long long int high = *max_element(nums.begin(),nums.end());
        long long int ans = high;
        while(low<=high)
        {
            long long int mid = (low+high)/2;
            if(isPossible(mid,nums))
            {
                ans=mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};