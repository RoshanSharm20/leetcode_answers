class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> rowminele;
        vector<int> colmaxele;
        vector<int> ans;
        for (int i = 0; i < matrix.size(); ++i) // loop to find the minvalues in each row
        {
            int minval = *min_element(matrix[i].begin(), matrix[i].end());
            rowminele.push_back(minval);
        }
        // loop to calculate the max values in each column
        for (int i = 0; i < matrix[0].size(); ++i) // since the size of row is not same as column therefore outer loop is size of each row
        {
            // int rowmin = *min_element(matrix[i].begin(),matrix[i].end());
            // rowminele.push_back(rowmin);
            int maxval = 0;
            for (int j = 0; j < matrix.size(); ++j) // inner loop is for row number
            {
                maxval = max(maxval, matrix[j][i]);
            }
            colmaxele.push_back(maxval);
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if ((matrix[i][j] == rowminele[i]) && (matrix[i][j] == colmaxele[j]))
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};