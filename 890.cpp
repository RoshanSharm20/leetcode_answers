class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        map<char, int> m; // map to store the character value pair
        vector<int> v;    // vector to store the produced pattern
        vector<string> ans;
        int i = 0;
        for (auto it : pattern)
        {
            if (m.find(it) != m.end())
                v.push_back(m[it]);
            else
            {
                v.push_back(i);
                m[it] = i;
                i++;
            }
        }
        for (auto word : words)
        {
            map<char, int> ma;
            vector<int> temp;
            int i = 0;
            for (auto it : word)
            {
                if (ma.find(it) != ma.end())
                    temp.push_back(ma[it]);
                else
                {
                    temp.push_back(i);
                    ma[it] = i;
                    i++;
                }
            }
            if (temp == v)
                ans.push_back(word);
        }
        return ans;
    }
};