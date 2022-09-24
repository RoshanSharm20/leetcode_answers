class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int count = 0;
        int cap = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'R')
                cap++;
            else
                cap--;
            if (cap == 0)
                count++;
        }
        return count;
    }
};