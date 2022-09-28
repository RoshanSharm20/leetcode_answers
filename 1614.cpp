class Solution
{
public:
    int maxDepth(string s)
    {
        int count = 0;
        int maxcount = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') // since the string is valid parenthesis strings then we can just keep count of maximum opening brackets
                count++;
            else if (s[i] == ')') // if there is a closing bracket we reduce the count
                count--;
            maxcount = max(count, maxcount); // store the maximum count value in maxcount
        }
        return maxcount;
    }
};