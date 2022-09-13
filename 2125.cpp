class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        vector<int> v;
        for (int i = 0; i < bank.size(); ++i)
        {
            int count = 0;
            for (int j = 0; j < bank[i].size(); ++j)
            {
                if (bank[i][j] == 1 + '0')
                    count++;
            }
            if (count != 0)
                v.push_back(count); // keep only the non-zero row values
        }
        int counter = 0;
        for (int i = 1; i < v.size(); ++i)
        {
            counter += v[i] * v[i - 1]; // for finding total laser combination between two rows multiply and accumulate the values
        }
        return counter;
    }
};