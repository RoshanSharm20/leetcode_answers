class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s.size() < t.size()) // case where all letters of s are use and an extra letter is added in t
            return false;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
};