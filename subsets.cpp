class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = pow(2, nums.size()); // calculate the total no of subsets that are going to be formed
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < nums.size(); j++) // run a loop only for the string length
            {
                if ((i & (1 << j)) != 0) // check which bit matches and input corresponding element
                    v.push_back(nums[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};