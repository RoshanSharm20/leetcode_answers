class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else
            {
                if (!st.empty())
                    st.pop();
                else
                    count++; // to keep count of closing brackets that do not have opening brackets
            }
        }
        return st.size() + count; // sum of left opening and closing brackets
    }
};