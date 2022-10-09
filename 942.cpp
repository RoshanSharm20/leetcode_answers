class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int start = 0, end = s.size();
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'I')
            {
                ans.push_back(start);
                start++;
            }
            else
            {
                ans.push_back(end);
                end--;
            }
        }
        ans.push_back(start); // after the loop start and end values will be same,append it in the answer vector to get resultant vector of n+1 size
        return ans;
    }
};