class Solution {
public:
    bool solution(int index,int target,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(target==0)
            return true;
        if(index==0)
            return nums[0]==target;
        if(dp[index][target]!=-1)
            return dp[index][target];
        bool nottake = solution(index-1,target,nums,dp);
        bool take = false;
        if(target>=nums[index])
            take = solution(index-1,target-nums[index],nums,dp);
        return dp[index][target]=take||nottake;
    }
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
            return false;
        int target = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return solution(nums.size()-1,target,nums,dp);
    }
};