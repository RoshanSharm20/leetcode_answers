class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int min_val=*min_element(nums.begin(),nums.end())-k;
        int max_val=*max_element(nums.begin(),nums.end())+k;
        vector<int> v(max_val-min_val+2,0);
        for(auto it:nums)
        {
            v[it-min_val-k]++;
            v[it-min_val+k+1]--;
        }
        int ans=v[0];
        for(int i=1;i<max_val-min_val+2;++i)
        {
            v[i]+=v[i-1];
            ans=max(ans,v[i]);
        }
        
        return ans;
    }
};