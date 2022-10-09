class Solution
{
public:
    char repeatedCharacter(string s)
    {
        map<char, int> m;
        for (int i = 0; i < s.size(); ++i)
        {
            if (m.find(s[i]) == m.end()) // if character has never appeared earlier then add it to the map
                m[s[i]]++;
            else
                return s[i]; // else return the element as it indicates that it is already present
        }
        return 0;
    }
};