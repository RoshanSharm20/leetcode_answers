class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) // precomputation is required in this question =>calculate the maximum row ans column values
    {
        vector<int> rowmaxele;
        vector<int> colmaxele;
        for (int i = 0; i < grid.size(); ++i)
        {
            int maxval = *max_element(grid[i].begin(), grid[i].end()); // finding the maximum row values
            rowmaxele.push_back(maxval);
            maxval = 0;
            for (int j = 0; j < grid.size(); ++j) // calculating the maximum column values
            {
                maxval = max(grid[j][i], maxval); // to traverse the column elements of each row
            }
            colmaxele.push_back(maxval);
        }

        int sum = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.size(); ++j)
            {
                sum = sum + (min(rowmaxele[i], colmaxele[j]) - grid[i][j]);
            }
        }
        return sum;
    }
};