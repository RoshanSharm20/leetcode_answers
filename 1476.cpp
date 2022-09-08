class SubrectangleQueries
{
public:
    vector<vector<int>> v;                              // we create 2D matrix on which we will perform the operations
    SubrectangleQueries(vector<vector<int>> &rectangle) // the rectangle matrix is passed in the constructor on creating the object in main fuction
    {
        // swap(v,rectangle);
        v = rectangle; // we copy the values of the rectangle,to perform the operations on it
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        for (int i = row1; i <= row2; ++i)
        {
            for (int j = col1; j <= col2; ++j)
            {
                v[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col)
    {
        return v[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */