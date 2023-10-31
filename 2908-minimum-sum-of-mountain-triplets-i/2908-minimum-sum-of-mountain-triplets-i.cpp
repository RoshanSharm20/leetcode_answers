class Solution {
public:
    int minimumSum(vector<int>& nums) 
    {
        int min_sum = INT_MAX;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                for(int k=j+1;k<nums.size();++k)
                {
                    if(i<j && j<k && nums[i]<nums[j] && nums[k]<nums[j])
                    {
                        min_sum=min(min_sum,nums[i]+nums[j]+nums[k]);
                    }
                }
            }
        }
        
        if(min_sum==INT_MAX)
            return -1;
        return min_sum;
    }
};