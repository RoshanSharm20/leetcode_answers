class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans(n);
        int index=1,pointer=n-1;
        while(index<n)
        {
            ans[index]=nums[pointer];
            pointer--;
            index+=2;
        }
        index=0;
        while(index<n)
        {
            ans[index]=nums[pointer];
            pointer--;
            index+=2;
        }
        nums=ans;
    }
};