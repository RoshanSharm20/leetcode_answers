class Solution {
public:
    void solution(vector<vector<char>>& board,vector<vector<bool>>& visited,int row,int col)
    {
        visited[row][col]=true;
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        
        for(int i=0;i<4;++i)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && !visited[nrow][ncol] && board[nrow][ncol]=='X')
                solution(board,visited,nrow,ncol);
        }
    }
    int countBattleships(vector<vector<char>>& board) 
    {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        int count=0;
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                if(!visited[i][j] && board[i][j]=='X')
                {
                    count++;
                    solution(board,visited,i,j);
                }
            }
        }
        return count;
    }
};