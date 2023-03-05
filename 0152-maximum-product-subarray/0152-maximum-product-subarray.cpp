class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int max_val = INT_MIN;
        int current_product = 1;
        for(int i=0;i<nums.size();++i)
        {
            current_product*=nums[i];
            max_val = max(max_val,current_product);
            if(current_product==0)
            {
                current_product=1;
            }
        }
        
        current_product = 1;
        for(int i=nums.size()-1;i>=0;--i)
        {
            current_product*=nums[i];
            max_val = max(max_val,current_product);
            if(current_product==0)
            {
                current_product=1;
            }
        }
        return max_val;
    }
};