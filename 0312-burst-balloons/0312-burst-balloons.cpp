class Solution {
public:
    int solution(int i,int j,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxi = -1e9;
        for(int k=i;k<=j;++k)
        {
            int coins = nums[i-1]*nums[k]*nums[j+1] + solution(i,k-1,nums,dp) + solution(k+1,j,nums,dp);
            maxi = max(coins,maxi);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        // return solution(1,n-2,nums,dp);
        for(int i=n-2;i>=1;--i)
        {
            for(int j=i;j<n-1;++j)
            {
                int maxi = -1e9;
                for(int k=i;k<=j;++k)
                {
                    int coins = nums[i-1]*nums[k]*nums[j+1] +dp[i][k-1] + dp[k+1][j];
                    maxi = max(coins,maxi);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n-2];
    }
};