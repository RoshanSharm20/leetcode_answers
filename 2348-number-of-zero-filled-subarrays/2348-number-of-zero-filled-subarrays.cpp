class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long int start=-1,end=-1,count=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==0)
            {
                if(start==-1)
                {
                    start=i;
                    end=i;
                }
                else
                {
                    end++;
                }
            }
            else
            {
                if(start!=-1 && start!=end)
                {
                    long long int size = end-start+1;
                    count+=((size*(size+1))/2);
                }
                else if(start!=-1 && start==end)
                {
                    count+=1;
                }
                start=-1;
                end=-1;
            }
        }
        if(start!=-1)
        {
            if(start==end)
                count+=1;
            else
            {
                long long int size = end-start+1;
                count+=((size*(size+1))/2);
            }
        }
        return count;
    }
};