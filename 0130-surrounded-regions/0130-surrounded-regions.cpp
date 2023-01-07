class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        queue<pair<int,int>> cells;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<m;++i)
        {
            if(board[0][i]=='O')
            {
                visited[0][i]=true;
                cells.push({0,i});
            }
        }
        for(int i=0;i<m;++i)
        {
            if(board[n-1][i]=='O')
            {
                visited[n-1][i]=true;
                cells.push({n-1,i});
            }
        }
        for(int i=0;i<n;++i)
        {
            if(board[i][0]=='O')
            {
                visited[i][0]=true;
                cells.push({i,0});
            }
        }
        for(int i=0;i<n;++i)
        {
            if(board[i][m-1]=='O')
            {
                visited[i][m-1]=true;
                cells.push({i,m-1});
            }
        }
        vector<int> drow = {0,-1,0,1};
        vector<int> dcol = {-1,0,1,0};
        while(!cells.empty())
        {
            auto it = cells.front();
            cells.pop();
            for(int i=0;i<4;++i)
            {
                    int newrow = it.first + drow[i];
                    int newcol = it.second + dcol[i];
                    if(newrow>=0 && newrow<board.size() && newcol>=0 && newcol<board[0].size() && !visited[newrow][newcol] && board[newrow][newcol]=='O')
                    {
                        visited[newrow][newcol]=true;
                        cells.push({newrow,newcol});
                    }
            }
        }
        
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                if(!visited[i][j])
                    board[i][j]='X';
            }
        }
    }
};