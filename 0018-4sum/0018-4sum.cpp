class Solution {
public:
    vector<vector<int>> two_sum(vector<int>& nums,long long int target,int start_index)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n-start_index<2)
            return ans;
        int left = start_index,right = n-1;
        while(left<right)
        {
            if(left!=start_index && nums[left]==nums[left-1])
            {
                left++;
                continue;
            }
            if(nums[left]+nums[right]==target)
            {
                vector<int> temp = { nums[left],nums[right]};
                ans.push_back(temp);
                left++;
                right--;
            }
            else if(nums[left]+nums[right]>target)
                right--;
            else 
                left++;
        }
        return ans;
    }
    vector<vector<int>> solution(vector<int>& nums,long long int target,int k,int start_index)
    {
        if(k==2)
        {
            return two_sum(nums,target,start_index);
        }
        
        vector<vector<int>> ans;
        int n = nums.size();
        if(n-start_index<k)
            return ans;
        for(int i=start_index;i<=n-k;++i)
        {
            if(i!=start_index && nums[i]==nums[i-1])
                continue;
            vector<vector<int>> res = solution(nums,target-nums[i],k-1,i+1);
            for(auto it:res)
            {
                it.push_back(nums[i]);
                ans.push_back(it);
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        return solution(nums,target,4,0);    
    }
};