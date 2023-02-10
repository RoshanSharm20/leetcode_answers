class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1),hash(n,0);
        int maxi=1;
        int last_index=0;
        for(int i=0;i<n;++i)
        {
            hash[i]=i;
            for(int j=0;j<i;++j)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            
            if(dp[i]>maxi)
            {
                maxi = dp[i];
                last_index = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[last_index]);
        while(hash[last_index]!=last_index)
        {
            last_index = hash[last_index];
            temp.push_back(nums[last_index]);
        }
        
        reverse(temp.begin(),temp.end());
        return temp;
    }
};