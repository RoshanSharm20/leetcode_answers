class Solution {
public:
    long long int mod = 1e9 + 7;
    int sumSubseqWidths(vector<int>& nums) 
    {
        long long int ans = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<long long int> power(n,1);
        for(int i=1;i<n;++i)
        {
            power[i]=(power[i-1]*2)%mod;
        }
        for(int i=0;i<nums.size();++i)
        {
            ans = (ans + nums[i]*(power[i]-power[n-i-1]))%mod;
        }
        return (int)ans;
    }
};