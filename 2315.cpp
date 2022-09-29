class Solution
{
public:
    int countAsterisks(string s)
    {
        int barcount = 0;
        int maxcount = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*' && barcount == 0)
            {
                maxcount++;
            }
            else
            {
                if (s[i] == '|' && barcount == 0) // maintain the count of the pair of the bars encountered
                    barcount++;
                else if (s[i] == '|' && barcount == 1)
                    barcount--;
            }
        }
        return maxcount;
    }
};