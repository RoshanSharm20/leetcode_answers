class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                curr = 0;
            else
            {
                curr++;
                count = max(curr, count);
            }
        }
        return count;
    }
};