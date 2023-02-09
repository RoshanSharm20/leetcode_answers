class Solution {
public:
    int solution(int index,int prev_index,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(index==nums.size())
            return 0;
        if(dp[index][prev_index+1]!=-1)
            return dp[index][prev_index+1];
        int nottake = solution(index+1,prev_index,nums,dp);
        int take = INT_MIN;
        if(prev_index==-1 || nums[index]>nums[prev_index])
            take = 1 + solution(index+1,index,nums,dp);
        return dp[index][prev_index+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solution(0,-1,nums,dp);
    }
};