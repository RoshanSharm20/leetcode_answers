class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int count = words.size();
        bool valid[26] = {false};
        for (auto &c : allowed)
        {
            valid[c - 'a'] = true;
        }
        for (auto &wor : words)
        {
            for (auto &all : wor)
            {
                if (valid[all - 'a'] != true)
                {
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};