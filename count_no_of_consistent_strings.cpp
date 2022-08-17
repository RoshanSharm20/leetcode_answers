class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int count = words.size(); // first declare all strings as valid
        bool valid[26] = {false}; // initalising as false
        for (auto &c : allowed)
        {
            valid[c - 'a'] = true; // only the allowed string characters are assigned true
        }
        for (auto &wor : words)
        {
            for (auto &all : wor)
            {
                if (valid[all - 'a'] != true) // check for the characters that are allowed
                {
                    count--;
                    break; // break is important so that only once count is reduced when one of the characters in string does not match
                }
            }
        }
        return count;
    }
};