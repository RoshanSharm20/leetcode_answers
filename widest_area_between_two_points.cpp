class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        vector<int> s;
        for (auto value : points)
        {
            s.push_back(value[0]);
        }
        int diff = 0;
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size() - 1; i++)
        {
            if ((s[i + 1] - s[i]) > diff) // just find the maximum distance between two coordinates
                diff = (s[i + 1] - s[i]);
        }
        return diff;
    }
};