class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
      sort(nums.begin(),nums.end());
        int n = nums.size();
        int max_val=0;
        for(int i=0;i<n;i++)
        {
          max_val=max(max_val,(nums[i]+nums[n-i-1]));
        }
     return max_val;
    }
};