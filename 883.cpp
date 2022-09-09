class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int row_max = 0, col_max = 0, z_max = 0; // calculate rowMax,colMax,z shadow coordinates
        for (int i = 0; i < grid.size(); ++i)
        {
            row_max += *max_element(grid[i].begin(), grid[i].end());
            int maxval = 0;
            for (int j = 0; j < grid.size(); ++j)
            {
                if (grid[j][i] != 0) // if grid value is non-zero then add 1 to z-coordinates
                    z_max++;
                maxval = max(maxval, grid[j][i]);
            }
            col_max += maxval;
        }

        return (row_max + col_max + z_max);
    }
};