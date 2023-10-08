class Solution {
public:
    int solution(int index1,int index2,vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp)
    {
        if(index1<0 || index2<0)
            return -1e9;
        
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        int ans = nums1[index1]*nums2[index2];
        ans=max(ans,(nums1[index1]*nums2[index2])+solution(index1-1,index2-1,nums1,nums2,dp));
        ans=max(ans,solution(index1-1,index2-1,nums1,nums2,dp));
        ans=max(ans,solution(index1-1,index2,nums1,nums2,dp));
        ans=max(ans,solution(index1,index2-1,nums1,nums2,dp));
        
        return dp[index1][index2]=ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        //something like pick and non pick
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return solution(nums1.size()-1,nums2.size()-1,nums1,nums2,dp);
    }
};