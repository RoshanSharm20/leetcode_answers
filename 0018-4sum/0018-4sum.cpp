class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()<4)
            return ans;
        long long int i = 0;
        while(i<=nums.size()-4)
        {
            if(i!=0 && nums[i]==nums[i-1])
            {
                i++;
                continue;
            }
            long long int target1=target-nums[i];
            long long int j=i+1;
            while(j<=nums.size()-3)
            {
                if(j!=i+1 && nums[j]==nums[j-1])
                {
                    j++;
                    continue;
                }
                long long int target2 = target1-nums[j];
                long long int k=j+1,l=nums.size()-1;
                while(k<l)
                {
                    if(k!=j+1 && nums[k]==nums[k-1])
                    {
                        k++;
                        continue;
                    }
                    if(nums[k]+nums[l]==target2)
                    {
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                    }
                    else if(nums[k]+nums[l]>target2)
                    {
                        l--;
                    }
                    else
                    {
                        k++;
                    }  
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};