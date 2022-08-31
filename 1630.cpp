class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ans;                  // vector of bool to store answers
        for (int i = 0; i < l.size(); ++i) // run for loop for the range vector l and r
        {
            vector<int> v;
            int low = l[i];
            int high = r[i];
            while (low <= high)
            {
                v.push_back(nums[low]);
                low++; // important statement otherwise memory limit is encountered
            }
            sort(v.begin(), v.end());
            int diff = v[1] - v[0];
            bool val = true;
            for (int i = 1; i < v.size(); ++i)
            {
                if ((v[i] - v[i - 1]) != diff)
                    val = false;
            }
            ans.push_back(val);
        }
        return ans;
    }
};