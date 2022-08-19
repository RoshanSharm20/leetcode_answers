class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int count = 0;
        vector<int> v;
        int n = pow(2, nums.size());
        for (int i = 0; i < n; i++)
        {
            int count_max = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if ((i & (1 << j)) != 0) // find out all the subsets and their OR values
                    count_max = (count_max | nums[j]);
            }
            v.push_back(count_max);
        }
        int max_val = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > max_val)
                max_val = v[i]; // find the maximum value in the vector
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == max_val) // find out number of times the maximum value is repeated
                count++;
        }
        return count;
    }
};