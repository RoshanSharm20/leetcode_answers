class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        bool one = false;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            if(nums[i]==1)
                one = true;
            if(nums[i]>=1 && nums[i]<=n)
                continue;
            else
                nums[i]=1;
        }
        if(one==false)
            return 1;
        for(int i=0;i<n;++i)
        {
            int index = abs(nums[i]);
            nums[index-1]=-abs(nums[index-1]);
        }
        
        for(int i=0;i<n;++i)
        {
            if(nums[i]>0)
                return i+1;
        }
        return n+1;
    }
};