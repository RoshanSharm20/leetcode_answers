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
        // vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        // return solution(nums.size()-1,target,nums,dp);
        vector<bool> prev(target+1,false);
        prev[0]=true;
        if(nums[0]<=target)
            prev[nums[0]]=true;
        for(int i=1;i<nums.size();++i)
        {
            vector<bool> curr(target+1,false);
            curr[0]=true;
            for(int tar=1;tar<=target;++tar)
            {
               bool nottake = prev[tar];
                bool take = false;
                if(tar>=nums[i])
                    take = prev[tar-nums[i]];
                curr[tar]=take||nottake;
            }
            prev=curr;
        }
        return prev[target];
    }
};