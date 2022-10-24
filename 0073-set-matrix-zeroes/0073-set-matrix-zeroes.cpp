class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        vector<pair<int,int>> cells;
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[0].size();++j)
            {
                if(matrix[i][j]==0)
                    cells.push_back({i,j});
            }
        }
        for(int i=0;i<cells.size();++i)
        {
            int row=cells[i].first;
            int col=cells[i].second;
            for(int j=0;j<matrix[0].size();++j)
                matrix[row][j]=0;
            for(int j=0;j<matrix.size();++j)
                matrix[j][col]=0;
        }
    }
};