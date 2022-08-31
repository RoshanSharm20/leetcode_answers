class Solution
{
public:
    string sortSentence(string s) // not optimized solution
    {
        set<pair<int, string>> str; // make a set stl to keep track of word order
        string ans;
        int start = 0; // to keep track of indes where to start copying of particular word in sentence
        int i = 0;
        int k = 1; // only to counter first word as it does not have leading whitespace
        while (i != s.size())
        {
            if (s[i] <= '9' && s[i] > '0')
            {
                if (k == 1)
                {
                    ans = s.substr(start, (i - start + 1));
                    str.insert({s[i], ans});
                    k++;
                }
                else
                {
                    ans = s.substr(start + 1, (i - start));
                    str.insert({s[i], ans});
                }
                start = i + 1;
                ans = "";
            }
            i++;
        }
        for (auto it : str)
        {
            ans += it.second;
        }
        for (int i = 0; i < ans.size(); ++i)
        {
            if (ans[i] <= '9')
                ans[i] = ' ';
        }
        string finans;
        for (int i = 0; i < (ans.size() - 1); ++i) // to remove ending space we copy string except the last whitespace
        {
            finans += ans[i];
        }
        return finans;
    }
};