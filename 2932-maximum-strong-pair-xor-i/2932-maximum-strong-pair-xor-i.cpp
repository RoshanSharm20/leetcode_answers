class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) 
    {
        int max_xor=0;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i;j<nums.size();++j)
            {
                if(abs(nums[i]-nums[j])<=min(nums[i],nums[j]))
                {
                    max_xor = max(max_xor,nums[i]^nums[j]);
                }
            }
        }
        return max_xor;
    }
};