class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        set<int> s;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            s.insert(nums[i]);
        }
        for (int i = 1; i <= nums.size(); ++i) // run a loop from 1 to n
        {
            if (s.find(i) == s.end()) // check if element is present in set or not
                ans.push_back(i);
        }
        return ans;
    }
};