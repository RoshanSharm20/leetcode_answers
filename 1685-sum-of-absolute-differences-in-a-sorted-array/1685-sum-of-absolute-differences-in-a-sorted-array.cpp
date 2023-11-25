class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        vector<int> left_sum,right_sum;
        int left=0,right=0;
        for(int i=0;i<nums.size();++i)
        {
            left+=nums[i];
            left_sum.push_back(left);
        }
        for(int i=nums.size()-1;i>=0;--i)
        {
            right+=nums[i];
            right_sum.push_back(right);
        }
        reverse(right_sum.begin(),right_sum.end());
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<nums.size();++i)
        {
            int x = ((nums[i]*(i+1))-left_sum[i])+(right_sum[i]-(nums[i]*(n-i)));
            ans.push_back(x);
        }
        
        return ans;
    }
};