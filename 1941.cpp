class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        map<int, int> m; // map to keep track of frequency of characters in the string
        for (int i = 0; i < s.size(); ++i)
            m[s[i] - 'a']++;
        int k = 0, count;
        for (auto it : m)
        {
            if (k == 0)
            {
                count = it.second; // to set the first value of the count,to use it compare in further steps
                k++;
            }
            else
            {
                if (it.second != count)
                    return false;
            }
        }
        return true;
    }
};