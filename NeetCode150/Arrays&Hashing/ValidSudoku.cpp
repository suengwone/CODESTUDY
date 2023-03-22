class Solution {
public:
    bool checkRow(vector<vector<char>>& board, int col)
    {
        set<char> check;
        char temp;
        for(int i=0; i<9; i++)
        {
            temp = board[i][col];

            if(check.find(temp) != check.end())
            {
                return false;
            }
            else if(temp != '.')
            {
                check.insert(temp);
            }
        }

        return true;
    }
    
    bool checkCol(vector<vector<char>>& board, int row)
    {
        set<char> check;
        char temp;
        for(int i=0; i<9; i++)
        {
            temp = board[row][i];

            if(check.find(temp) != check.end())
            {
                return false;
            }
            else if(temp != '.')
            {
                check.insert(temp);
            }
        }
        
        return true;
    }

    bool checkSquare(vector<vector<char>>& board, int row, int col)
    {
        set<char> check;
        char temp;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                temp = board[row+i][col+j];

                if(check.find(temp) != check.end())
                {
                    return false;
                }
                else if(temp != '.')
                {
                    check.insert(temp);
                }
            }
        }
        
        return true;
    }

    bool validSudoku(vector<vector<char>>& board, int row, int col)
    {
        return checkRow(board, col) && checkCol(board, row) && checkSquare(board, row-row%3, col-col%3);
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(validSudoku(board,i,j) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};
