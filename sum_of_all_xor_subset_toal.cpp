class Solution
{
public:
    int countxor(vector<int> &nums, int n, int sum) // solution using recursion method
    {
        if (n == 0)
            return sum;
        return countxor(nums, n - 1, sum ^ nums[n - 1]) + //(first part include the element and pass the xor'ed value
               countxor(nums, n - 1, sum);                // (second part not include the element) and pass the sum value as it is
    }
    int subsetXORSum(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        int total = countxor(nums, n, sum); // function call
        return total;
    }
};