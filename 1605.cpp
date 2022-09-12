class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), 0)); // initialize a matrix
        for (int i = 0; i < rowSum.size(); ++i)
        {
            for (int j = 0; j < colSum.size(); ++j)
            {
                int n = min(rowSum[i], colSum[j]); // find the minimum value between the rowSum and colSum at [i][j]
                ans[i][j] = n;
                rowSum[i] -= n; // subtract the input value from both rowSum and colSum
                colSum[j] -= n;
            }
        }
        return ans;
    }
};