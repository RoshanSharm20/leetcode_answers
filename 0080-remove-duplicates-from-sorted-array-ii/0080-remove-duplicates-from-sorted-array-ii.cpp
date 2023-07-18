class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int element=nums[0],count=0,curr_count=1;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]==nums[i-1])
                curr_count++;
            else
            {
                if(curr_count>=2)
                {
                    nums[count]=element;
                    count++;
                    nums[count]=element;
                    count++;
                }
                else
                {
                    nums[count]=element;
                    count++;
                }
                curr_count=1;
                element=nums[i];
            }
        }
        
        if(curr_count>=2)
        {
            nums[count]=element;
            count++;
            nums[count]=element;
            count++;
        }
        else
        {
            nums[count]=element;
            count++;
        }
        return count;
    }
};