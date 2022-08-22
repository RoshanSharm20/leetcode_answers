class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int res = 1; // initilaze frequency as 1 for corner case of only one element
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[res - 1] != nums[i]) // iterate the array and store the distinct elements
            {
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }
};