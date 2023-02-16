class Solution {
public:
    int dp[1001];
    int find(vector<int>&nums,int target)
    {
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int a=0;
        for(int i=0;i<nums.size();++i)
        {
            if(target-nums[i]>=0)
            a+=find(nums,target-nums[i]);
        }
        return dp[target]=a;
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        memset(dp,-1,sizeof(dp));
        // vector<int> dp(target+1,-1);/
        return find(nums,target);
    }
};