class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        vector<int> ans(1001,0);
        for(int i=0;i<nums.size();++i)
            ans[nums[i]]++;
        for(int i=ans.size()-2;i>=0;--i)
            ans[i]=ans[i]+ans[i+1];
        for(int i=0;i<ans.size();++i)
        {
            if(ans[i]==i)
                return i;
        }
        return -1;
    }
};