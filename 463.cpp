class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int total = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    int val = 4; // let number of sides be 4 at first for particular cell
                    if (i > 0)   // 4 comparisons have to be done to avoid corner cases of accesing invalid cells
                        if (grid[i - 1][j] == 1)
                            val--;
                    if (i < grid.size() - 1)
                        if (grid[i + 1][j] == 1)
                            val--;
                    if (j > 0)
                        if (grid[i][j - 1] == 1)
                            val--;
                    if (j < grid[i].size() - 1)
                        if (grid[i][j + 1] == 1)
                            val--;
                    total += val;
                }
            }
        }
        return total;
    }
};