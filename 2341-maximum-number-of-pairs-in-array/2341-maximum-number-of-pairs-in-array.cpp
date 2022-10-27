class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) 
    {
        int const CHAR = 101;
        vector<int> count(CHAR,0);
        int count_pairs=0,count_rem=0;
        for(int i=0;i<nums.size();++i)
            count[nums[i]]++;
        for(int i=0;i<count.size();++i)
        {
            count_pairs+=(count[i]/2);
            count_rem+=(count[i]%2);
        }
        vector<int> ans;
        ans.push_back(count_pairs);
        ans.push_back(count_rem);
        return ans;
    }
};