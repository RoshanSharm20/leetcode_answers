class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        return (max(nums[0] * nums[1] * nums[2], nums[0] * nums[nums.size() - 1] * nums[nums.size() - 2]));
    }
};
// the maximum product can be either first 3 numbers of descending sorted array or a case where last 2 numbers are most negative(product is +ve) and first number is positive