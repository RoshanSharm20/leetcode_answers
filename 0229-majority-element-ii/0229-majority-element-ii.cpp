class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int val1=nums[0],count1=1,val2=nums[0],count2=0;
        int i=1;
        while(i<nums.size())
        {
            if(nums[i]==val1)
                count1++;
            else if(nums[i]==val2)
                count2++;
            else
            {
                if(count1==0)
                {
                    val1=nums[i];
                    count1=1;
                }
                else if(count2==0)
                {
                    val2=nums[i];
                    count2=1;
                }
                else
                {
                    count1--;
                    count2--;
                }
            }
            i++;
        }
        int n = nums.size();
        int count_1=0,count_2=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==val1)
                count_1++;
            else if(nums[i]==val2)
                count_2++;
        }
        vector<int> ans;
        if(count_1>(n/3))
            ans.push_back(val1);
        if(count_2>(n/3))
            ans.push_back(val2);
        return ans;
    }
};