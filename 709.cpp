class Solution
{
public:
    string toLowerCase(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= 'A' && s[i] <= 'Z') // just check if it is uppercase letter using its ascii values and convert it to its lowercase value
                s[i] = s[i] + 32;
        }
        return s;
    }
};