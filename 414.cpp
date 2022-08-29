class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int freq = 1; // keep a counter variable to find the third maximum element
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
                freq++;
            if (freq == 3)
                return nums[i];
        }
        return nums[0];
    }
};