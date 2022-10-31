class Solution {
public:
    bool divideArray(vector<int>& nums)
    {
      sort(nums.begin(),nums.end());
        int count=true;
        for(int i=0;i<(nums.size()/2);i++)
        {
            if(nums[i*2]!=nums[(2*i)+1])
                count= false;
        }
        return count;
    }
};