class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        sort(nums.begin(), nums.end()); // sort to get the pattern in increasing order
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == original) // compare if found true multiply original value by 2
                original *= 2;
        }
        return original;
    }
};