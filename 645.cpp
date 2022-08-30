class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> ans;
        set<int> s; // introducing set to keep track of unique elements
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                ans.push_back(nums[i]);
            }
            s.insert(nums[i]);
        }
        s.insert(nums[nums.size() - 1]); // last element also must be included
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (s.find(i) == s.end())
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};