class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int el = nums[i];
            if (el != 0) // the selected element is non-zero then proceed to subtract all numbers with the selected element
            {
                for (int j = i; j < nums.size(); ++j)
                {
                    nums[j] = nums[j] - el;
                }
                count++; // keep count of number of times subtraction has been done
            }
        }
        return count;
    }
};