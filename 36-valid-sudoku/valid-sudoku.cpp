class Solution {
public:
    bool check(vector<vector<char>>& board,int row,int col,char d)
    {
        for(int i=0;i<9;i++)
        {
            if(col != i && board[row][i] == d)
            return false;
        }
        for(int i=0;i<9;i++)
        {
            if(row != i && board[i][col] == d)
            return false;
        }
        int i_new = (row/3)*3;
        int j_new = (col/3)*3;

        for(int i=i_new;i<i_new+3;i++)
        {
            for(int j=j_new;j<j_new+3;j++)
            {
                if(i == row && j == col)
                continue;

                if(board[i][j]==d)
                return false;
            }
        }
    return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.')
                continue;

                if(!check(board,i,j,board[i][j]))
                return false;
            }
        }
    return true;
    }
};