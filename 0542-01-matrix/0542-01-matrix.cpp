class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        vector<vector<bool>> visited(mat.size(),vector<bool>(mat[0].size(),false));
        vector<vector<int>> distance(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>> cells;
        for(int i=0;i<mat.size();++i)
        {
            for(int j=0;j<mat[0].size();++j)
            {
                if(mat[i][j]==0)
                {
                    cells.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        while(!cells.empty())
        {
            auto it = cells.front();
            cells.pop();
            for(int i=0;i<4;++i)
            {
                int newrow = it.first.first + delrow[i];
                int newcol = it.first.second + delcol[i];
                if(newrow>=0 && newrow<mat.size() && newcol>=0 && newcol<mat[0].size() && !visited[newrow][newcol] && mat[newrow][newcol]==1)
                {
                    visited[newrow][newcol]=true;
                    distance[newrow][newcol]=it.second+1;
                    cells.push({{newrow,newcol},it.second+1});
                }
            }
        }
        return distance;
    }
};