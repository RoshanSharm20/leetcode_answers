class Solution {
public:
    int partitionDisjoint(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> right_min(n+1,INT_MIN),left_max(n);
        int min_val = INT_MAX;
        for(int i=n-1;i>=0;--i)
        {
            min_val = min(min_val,nums[i]);
            right_min[i]=min_val;
        }
        
        int max_val = INT_MIN;
        for(int i=0;i<n;++i)
        {
            max_val = max(max_val,nums[i]);
            left_max[i]=max_val;
        }
        
        for(int i=0;i<n;++i)
        {
            if(left_max[i]<=right_min[i+1])
                return i+1;
        }
        return 0;
    }
};