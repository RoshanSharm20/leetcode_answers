class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        int count = 0;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=0;j<nums.size();++j)
            {
                if(i!=j)
                {
                    string str1 = nums[i]+nums[j];
                    if(str1==target)
                        count++;
                    string str2= nums[j]+nums[i];
                    if(str2==target)
                        count++;
                }
            }
        }
        return count/2;
    }
};