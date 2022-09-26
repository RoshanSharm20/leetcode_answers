class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        char col1 = s[0];
        char col2 = s[3];
        char row1 = s[1];
        char row2 = s[4];
        vector<string> ans;
        for (int i = col1; i <= col2; ++i)
        {
            for (int j = row1; j <= row2; ++j)
            {
                string str = "";
                str += char(i);
                str += char(j);
                ans.push_back(str);
            }
        }
        return ans;
    }
};