class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        set<int> s1;
        set<int> s2;
        map<int, int> m;
        for (int i = 0; i < nums1.size(); ++i)
        {
            s1.insert(nums1[i]); // only unique elements must be present to check
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            s2.insert(nums2[i]);
        }
        for (auto &val : s1)
            m[val]++;
        for (auto &val : s2)
            m[val]++;
        for (auto pr : m)
        {
            if (pr.second >= 2)
                ans.push_back(pr.first);
        }
        return ans;
    }
};