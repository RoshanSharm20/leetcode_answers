class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        vector<vector<int>> ans;
        if (r * c != mat.size() * mat[0].size()) // check if resizing of matrix is possible or not
            return mat;
        else
        {
            vector<int> temp;
            int count = 1;
            for (int i = 0; i < mat.size(); ++i)
            {
                for (int j = 0; j < mat[i].size(); ++j)
                {
                    temp.push_back(mat[i][j]);
                    if (count != c) // when no of element match the column size push it to ans matrix,clear temp and start storing again
                        count++;
                    else
                    {
                        ans.push_back(temp);
                        temp.clear();
                        count = 1;
                    }
                }
            }
        }
        return ans;
    }
};