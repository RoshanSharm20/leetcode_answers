class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        vector<vector<int>> ans;
        for (int i = 1; i < grid.size() - 1; ++i)
        {
            vector<int> temp1;
            vector<int> temp2;
            int maxele = 0;
            for (int j = 1; j < grid.size() - 1; ++j)
            {
                int row1max = *max_element(grid[i - 1].begin() + (j - 1), grid[i - 1].begin() + (j + 2));
                temp1.push_back(row1max);
                int row2max = *max_element(grid[i].begin() + (j - 1), grid[i].begin() + (j + 2));
                temp1.push_back(row2max);
                int row3max = *max_element(grid[i + 1].begin() + (j - 1), grid[i + 1].begin() + (j + 2));
                temp1.push_back(row3max);
                maxele = *max_element(temp1.begin(), temp1.end());
                temp1.clear();
                temp2.push_back(maxele);
            }
            ans.push_back(temp2);
        }
        return ans;
    }
};