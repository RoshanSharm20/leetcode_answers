class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        int n=nums.size();
        vector<string> ans;
        if(n==0)
            return ans;
        int start=nums[0],count=1;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]==nums[i-1]+1)
                count++;
            else
            {
                if(count>1)
                {
                    string st = to_string(start)+"->"+to_string(nums[i-1]);
                    ans.push_back(st);
                }
                else
                {
                    string st = to_string(start);
                    ans.push_back(st);
                }
                count=1;
                start=nums[i];
            }
        }
        if(count>1)
        {
            string st = to_string(start)+"->"+to_string(nums[n-1]);
            ans.push_back(st);  
        }
        else
        {
            string st = to_string(start);
            ans.push_back(st);   
        }
        
        return ans;
    }
};