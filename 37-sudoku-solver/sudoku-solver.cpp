class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int row,int col,char d)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i] == d)
            return false;
        }
        
        for(int i=0;i<9;i++)
        {
            if(board[i][col] == d)
            return false;
        }

        int i_new = (row/3)*3;
        int j_new = (col/3)*3;

        for(int i=i_new;i<i_new+3;i++)
        {
            for(int j=j_new;j<j_new+3;j++)
            {
                if(board[i][j]==d)
                return false;
            }
        }
    return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.')
                {
                    for(int d='1';d<='9';d++)
                    {
                        if(isvalid(board,i,j,d))
                        {
                            board[i][j] = d;

                            if(solve(board))
                            return true;
                            board[i][j] = '.';
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};