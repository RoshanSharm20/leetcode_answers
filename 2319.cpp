class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int low = 0, high = grid.size() - 1; // keep pointers for the positions of x using low and high in respective rows
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.size(); ++j)
            {
                if ((j == low) || (j == high))
                {
                    if (grid[i][j] == 0)
                        return false;
                }
                else
                {
                    if (grid[i][j] != 0)
                        return false;
                }
            }
            low++;
            high--;
        }
        return true;
    }
};