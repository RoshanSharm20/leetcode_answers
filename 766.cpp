class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        bool check = true;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if ((i - 1) >= 0 && (j - 1) >= 0)             // to check if the address being accessed is valid or not
                    if (matrix[i][j] != matrix[i - 1][j - 1]) // if the previous diagonal element is not same to the current element return false
                    {
                        return false;
                    }
            }
        }
        return true;
    }
};