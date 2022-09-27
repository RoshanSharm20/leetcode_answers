class Solution
{
public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i)
        {
            int count = 0;
            int startrow = startPos[0];
            int startcol = startPos[1];
            for (int j = i; j < s.size(); ++j)
            {
                if ((s[j] == 'R') && (startcol + 1 != n))
                {
                    startcol += 1;
                    count++;
                }
                else if ((s[j] == 'L') && (startcol - 1 >= 0))
                {
                    startcol -= 1;
                    count++;
                }
                else if ((s[j] == 'U') && (startrow - 1 >= 0))
                {
                    startrow -= 1;
                    count++;
                }
                else if ((s[j] == 'D') && (startrow + 1 != n))
                {
                    startrow += 1;
                    count++;
                }
                else
                    break;
            }
            ans.push_back(count);
        }
        return ans;
    }
};