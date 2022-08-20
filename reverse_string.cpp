class Solution
{
public:
    vector<char> swaping(vector<char> &s, int start, int end)
    {
        if (start >= end)
            return s;

        swap(s[start], s[end]);                // swap the start and end of the string
        return swaping(s, start + 1, end - 1); // reduce length 1 from both the sides and recursion function call
    }
    void reverseString(vector<char> &s)
    {
        swaping(s, 0, s.size() - 1);
    }
};