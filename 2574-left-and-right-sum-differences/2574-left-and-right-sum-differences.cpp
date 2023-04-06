class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> left(n,0),right(n,0);
        int left_sum=0,right_sum=0;
        for(int i=1;i<nums.size();++i)
        {
            left[i]=left_sum+nums[i-1];
            left_sum=left[i];
        }
        
        for(int i=nums.size()-2;i>=0;--i)
        {
            right[i]=right_sum+nums[i+1];
            right_sum=right[i];
        }
        
        vector<int> ans(n,0);
        for(int i=0;i<n;++i)
        {
            ans[i]=abs(left[i]-right[i]);
        }
        return ans;
    }
};