class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        if (matrix.size() == matrix[0].size()) // for square matrix
        {
            for (int i = 0; i < matrix.size(); ++i)
            {
                for (int j = 0; j <= i; ++j)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        else
        {
            vector<vector<int>> ans; // for non square matrix
            vector<int> temp;
            for (int i = 0; i < matrix[0].size(); ++i) // traversing through all the column elements
            {
                for (int j = 0; j < matrix.size(); ++j)
                {
                    temp.push_back(matrix[j][i]);
                }
                ans.push_back(temp);
                temp.clear();
            }
            return ans;
        }
        return matrix;
    }
};