class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int count=1;
        int ele=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]==ele)
                count++;
            else if(count>(nums.size()/3))
            {
                ans.push_back(ele);
                ele=nums[i];
                count=1;
            }
            else
            {
                ele=nums[i];
                count=1;
            }
        }
        if(count>(nums.size()/3))
            ans.push_back(ele);
        return ans;
    }
};