class Solution
{
public:
    int countPoints(string rings)
    {
        vector<string> v(10, "");
        int count = 0;
        for (int i = 0; i < rings.size(); i = i + 2)
        {
            v[rings[i + 1] - '0'] += rings[i];
        }
        for (int i = 0; i < v.size(); ++i)
        {
            set<char> s;
            for (int j = 0; j < v[i].size(); ++j)
            {
                s.insert(v[i][j]);
            }
            if (s.size() == 3)
                count++;
        }
        return count;
    }
};