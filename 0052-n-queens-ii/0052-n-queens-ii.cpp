class Solution {
public:
    int count=0;
    bool isSafe(vector<vector<int>>&board,int row,int col)
    {
        for(int i=0;i<=row;++i)
        {
            if(board[i][col]==1)
                return false;
        }
        
        int i=row;
        int j=col;
        while(i>=0 && j>=0)
        {
            if(board[i][j]==1)
                return false;
            --i;
            --j;
        }
        
        i=row;
        j=col;
        while(i>=0 && j<board.size())
        {
            if(board[i][j]==1)
                return false;
            --i;
            ++j;
        }
        return true;
    }
    void solution(vector<vector<int>>& board,int row)
    {
        if(row==board.size())
        {
            count++;
            return;
        }
        
        for(int col=0;col<board.size();++col)
        {
            if(isSafe(board,row,col))
            {
                board[row][col]=1;
                solution(board,row+1);
                board[row][col]=0;
            }
        }
    }
    int totalNQueens(int n) 
    {
        vector<vector<int>> board(n,vector<int>(n,0));
        solution(board,0);
        return count;
    }
};