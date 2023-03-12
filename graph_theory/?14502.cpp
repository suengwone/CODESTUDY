// 연구소

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> point;

int N,M;

point Plus(point a, point b)
{
    return point(a.first + b.first, a.second + b.second);
}

point Minus(point a, point b)
{
    return point(a.first - b.first, a.second - b.second);
}

class Board
{
private:
    int row, col;
    vector<vector<int>> board;
    int SafeCount;
    queue<point> virusPoints;

public:
    Board(int _row, int _col);
    void InitBoard();
    void Set3Walls();
    void CheckSafeArea(vector<vector<int>> _board);
    int PrintSafeCount() {return SafeCount;}
    void TimeFlow(vector<vector<int>> _tempBoard);
    ~Board();
};

Board::Board(int _row, int _col)
{
    row = _row;
    col = _col;
    SafeCount = _row*_col;

    board.assign(row, vector<int>(col));
}

void Board::InitBoard()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin >> board[i][j];

            if(board[i][j] == 2)
            {
                virusPoints.push(point(i,j));
            }
        }
    }

    Set3Walls();
}

void Board::CheckSafeArea(vector<vector<int>> _board)
{
    int count = 0;

    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            if(_board[i][j] == 0)
            {
                count += 1;
            }
        }
    }

    if(SafeCount > count)
    {
        SafeCount = count;
    }

    return;
}

void Board::Set3Walls()
{
    vector<vector<int>> tempBoard = board;
    int wallCount = 0;

    // 1인 벽 주변에 3개의 벽을 세움

    TimeFlow(tempBoard);

    return;
}
const point dir4[4] = {point(1,0), point(0,1), point(-1,0), point(0,-1),};

void Board::TimeFlow(vector<vector<int>> _tempBoard)
{
    point tempPoint;
    while(virusPoints.empty() != true)
    {
        tempPoint = virusPoints.front();
        virusPoints.pop();

        for(int i=0; i<4; i++)
        {
            tempPoint = Plus(tempPoint, dir4[i]);

            if((tempPoint.first >= 0 && tempPoint.first < row) && (tempPoint.second >= 0 && tempPoint.second < col))
            {
                if(_tempBoard[tempPoint.first][tempPoint.second] == 0)
                {
                    _tempBoard[tempPoint.first][tempPoint.second] = 1;
                    virusPoints.push(tempPoint);
                }
            }

            tempPoint = Minus(tempPoint, dir4[i]);
        }
    }

    CheckSafeArea(_tempBoard);
}

Board::~Board()
{

}

int main()
{
    for(int i=0; i<3; i++)
    {
        cin>>N>>M;

        Board newBoard(N,M);

        newBoard.InitBoard();

        cout << newBoard.PrintSafeCount() << '\n';
    }
    
    return 0;
}
