class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<nums.size()-1)
        {
            if(i!=0 && nums[i]==nums[i-1])
            {
                i++;
                continue;
            }
            int target = -nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(j!=i+1 && nums[j]==nums[j-1])
                {
                    j++;
                    continue;
                }
                if(nums[j]+nums[k]==target)
                {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]>target)
                    k--;
                else
                    j++;
            }
            i++;
        }
        return ans;
    }
};