class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> left(n),right(n),result(n);
        int leftp=1,rightp=1;
        for(int i=0;i<n;++i)
        {
            leftp*=nums[i];
            left[i]=leftp;
            rightp*=nums[n-1-i];
            right[n-1-i]=rightp;
        }
        
        for(int i=0;i<n;++i)
        {
            if(i==0)
                result[i]=1*right[i+1];
            else if(i==n-1)
                result[i]=left[i-1]*1;
            else
                result[i]=left[i-1]*right[i+1];
        }
        return result;
    }
};