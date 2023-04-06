class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int xo=0;
        for(int i=0;i<nums.size();++i)
        {
            xo^=nums[i];
        }
        int ind=0;
        while(true)
        {
            if(xo&(1<<ind))
                break;
            else
                ind++;
        }
        
        int first=0,second=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]&(1<<ind))
                first^=nums[i];
            else
                second^=nums[i];
        }
        
        return {first,second};
    }
};