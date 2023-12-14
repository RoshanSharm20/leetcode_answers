class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        vector<pair<int,int>> row_counts;
        vector<pair<int,int>> col_counts;
        
        for(int i=0;i<grid.size();++i)
        {
            int row_ones = count(grid[i].begin(),grid[i].end(),1);
            int row_zero = count(grid[i].begin(),grid[i].end(),0);
            row_counts.push_back({row_ones,row_zero});
        }
        
        for(int i=0;i<grid[0].size();++i)
        {
            int col_zero=0,col_ones=0;
            for(int j=0;j<grid.size();++j)
            {
                if(grid[j][i]==0)
                    col_zero++;
                else
                    col_ones++;
            }
            col_counts.push_back({col_ones,col_zero});
        }
        vector<vector<int>> diff(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                diff[i][j]=(row_counts[i].first + col_counts[j].first - row_counts[i].second - col_counts[j].second);
            }
        }
        return diff;
    }
};