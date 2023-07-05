class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        nums.insert(nums.begin(),0);
        nums.push_back(0);
        vector<int> left_ones(n+2,0);
        vector<int> right_ones(n+2,0);
        
        for(int i=1;i<=n;++i)
        {
            if(nums[i]==1)
                left_ones[i]=left_ones[i-1]+1;
        }
        for(int i=n;i>=0;--i)
        {
            if(nums[i]==1)
                right_ones[i]=right_ones[i+1]+1;
        }
        
        int max_val=0;
        for(int i=1;i<=n;++i)
        {
            max_val=max(max_val,left_ones[i-1]+right_ones[i+1]);
        }
        return max_val;
    }
};