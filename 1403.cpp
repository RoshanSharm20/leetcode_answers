class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int i;
        for (i = 0; i < nums.size(); ++i)
        {
            int sum1 = accumulate(nums.begin(), nums.begin() + i, 0);
            if (sum1 > (sum - sum1))
                break;
        }
        vector<int> ans(nums.begin(), nums.begin() + i);
        return ans;
    }
};