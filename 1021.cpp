class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int count = 0;
        string str = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' && count == 0)
            {
                count++;
            }
            else if (s[i] == '(' && count != 0)
            {
                count++;
                str += s[i];
            }
            else if (s[i] == ')' && count > 1)
            {
                count--;
                str += s[i];
            }
            else
            {
                count--;
            }
        }
        return str;
    }
};