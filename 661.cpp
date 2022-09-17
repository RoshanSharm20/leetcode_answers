class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < img.size(); ++i)
        {
            vector<int> temp;
            int count = 0;
            for (int j = 0; j < img[0].size(); ++j)
            {
                int val = 0;
                val += img[i][j];
                count++;
                if ((i - 1) >= 0)
                {
                    val += img[i - 1][j];
                    count++;
                    if ((j - 1) >= 0)
                    {
                        val += img[i - 1][j - 1];
                        count++;
                    }
                    if ((j + 1) < img[0].size())
                    {
                        val += img[i - 1][j + 1];
                        count++;
                    }
                }
                if ((i + 1) < img.size())
                {
                    val += img[i + 1][j];
                    count++;
                    if ((j - 1) >= 0)
                    {
                        val += img[i + 1][j - 1];
                        count++;
                    }
                    if ((j + 1) < img[0].size())
                    {
                        val += img[i + 1][j + 1];
                        count++;
                    }
                }
                if ((j - 1) >= 0)
                {
                    val += img[i][j - 1];
                    count++;
                }
                if ((j + 1) < img[0].size())
                {
                    val += img[i][j + 1];
                    count++;
                }
                temp.push_back((val / count));
                count = 0;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};