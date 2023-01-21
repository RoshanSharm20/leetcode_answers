class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(vector<vector<char>>& board,int row,int col)
    {
        int i=row;
        int j=col;
        while(i>=0)
        {
            if(board[i][col]=='Q')
                return false;
            --i;
        }
        i=row;
        j=col;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')
                return false;
            --i;
            --j;
        }
        i=row;
        j=col;
        while(i>=0 && j<board.size())
        {
            if(board[i][j]=='Q')
                return false;
            --i;
            ++j;
        }
        return true;
        
    }
    void solution(vector<vector<char>>& board,int row)
    {
        if(row==board.size())
        {
            vector<string> t;
            for(int i=0;i<board.size();++i)
            {
                string temp="";
                for(int j=0;j<board.size();++j)
                {
                    temp+=board[i][j];
                }
                t.push_back(temp);
            }
            ans.push_back(t);
            return;
        }
        for(int col=0;col<board.size();++col)
        {
            
            if(isSafe(board,row,col))
            {
                board[row][col]='Q';
                solution(board,row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        solution(board,0);
        return ans;
    }
};