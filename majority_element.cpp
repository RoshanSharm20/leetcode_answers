class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int freq = 1;
        int i = 1;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        sort(nums.begin(), nums.end()); // for arranging elements in sorted order to find frequency easily
        while (i < n)
        {
            while ((i < n) && (nums[i] == nums[i - 1]))
            {
                freq++;
                i++;
            }
            if (freq > (n / 2))
                return nums[i - 1];

            i++;
            freq = 1;
        }

        return nums[0]; // just to counter the error of "does not give output in all control paths"
    }
};