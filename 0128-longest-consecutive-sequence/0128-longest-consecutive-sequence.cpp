class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> s;
        for(int i=0;i<nums.size();++i)
            s.insert(nums[i]);
        int curr=0,max_count=0;
        int prev_ele=0;
        int first=0;
        for(auto it : s)
        {
            if(first==0)
            {
                prev_ele=it;
                curr=1;
                max_count=1;
                first++;
            }
            else
            {
                if(prev_ele +1 == it)
                {
                    curr++;
                    max_count=max(curr,max_count);
                    prev_ele=it;
                }
                else
                {
                    curr=1;
                    prev_ele=it;
                }
            }
        }
        return max_count;
    }
};