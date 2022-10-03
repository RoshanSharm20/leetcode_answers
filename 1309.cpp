class Solution
{
public:
    string freqAlphabets(string s)
    {
        map<int, char> m;
        char alphabet = 'a';
        for (int i = 1; i <= 26; ++i)
        {
            m[i] = alphabet;
            alphabet++;
        }
        string str = "";
        for (int i = s.size() - 1; i >= 0;) // traversing from behind is much easier to compare
        {
            int index;
            if (s[i] == '#')
            {
                index = s[i - 1] - '0';
                index += (s[i - 2] - '0') * 10;
                str += m[index];
                i = i - 3;
            }
            else
            {
                index = s[i] - '0';
                str += m[index];
                --i;
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};