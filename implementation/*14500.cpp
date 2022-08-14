// 테트로미노 1번째 풀이

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> check;
int Max_value = 0;
int N, M;

pair<int, int> dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void find_maxValue(int count, int cur_value, int row, int col) {
    vector<pair<int, int>> pos;

    if (count == 4) {
        Max_value = Max_value < cur_value ? cur_value : Max_value;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int move_row = dir[i].first + row;
        int move_col = dir[i].second + col;

        if (move_row >= 0 && move_col >= 0 && move_row < N && move_col < M) {
            pos.push_back(make_pair(move_row, move_col));
            if (check[move_row][move_col]) continue;
            check[move_row][move_col] = true;
            find_maxValue(count + 1, cur_value + board[move_row][move_col], move_row, move_col);
            check[move_row][move_col] = false;
        }
    }

    if (pos.size() == 4) {
        for (int i = 0; i < 4; i++) {
            int cur_value = board[row][col];
            for (int j = 0; j < 4; j++) {
                if (i != j) {
                    cur_value += board[pos[j].first][pos[j].second];
                }
            }
            Max_value = max(Max_value, cur_value);
        }
    }
    else if (pos.size() == 3) {
        Max_value = max(Max_value,
            board[pos[0].first][pos[0].second] + board[pos[1].first][pos[1].second] + board[pos[2].first][pos[2].second]
            + board[row][col]);
    }

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    board = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    check = vector<vector<bool>>(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            check[i][j] = true;
            find_maxValue(1, board[i][j], i, j);
            check[i][j] = false;
        }
    }

    cout << Max_value << '\n';
}


// 테트로미노 2번째 

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > arr;
int MaxValue = 0;
int N,M;

pair<int,int> PairMinus(pair<int,int> _A, pair<int,int> _B)
{
    return pair<int,int>(_A.first - _B.first, _A.second - _B.second);
}

void FindMaxValue(int col, int row, int cur_value, int count, vector< pair<int,int> > check)
{
    check[count] = pair<int,int>(col,row);

    if(count == 4)
    {
        if(MaxValue < cur_value)
        {
            MaxValue = cur_value;
        }
        return;
    }

    if(count == 1)
    {
        if(col + 1 < N)
        {
            FindMaxValue(col + 1, row, cur_value + arr[col+1][row],count+1,check);
        }
        if(col - 1 >= 0)
        {
            FindMaxValue(col - 1, row, cur_value + arr[col-1][row],count+1,check);
        }
        if(row + 1 < M)
        {
            FindMaxValue(col, row + 1, cur_value + arr[col][row+1],count+1,check);
        }
        if(row - 1 >= 0)
        {
            FindMaxValue(col, row - 1, cur_value + arr[col][row-1],count+1,check);
        }
    }
    else
    {
        if(col + 1 < N && col + 1 != check[count-1].first)
        {
            FindMaxValue(col + 1, row, cur_value + arr[col+1][row],count+1,check);
        }
        if(col - 1 >= 0 && col - 1 != check[count-1].first)
        {
            FindMaxValue(col - 1, row, cur_value + arr[col-1][row],count+1,check);
        }
        if(row + 1 < M && row + 1 != check[count-1].second)
        {
            FindMaxValue(col, row + 1, cur_value + arr[col][row+1],count+1,check);
        }
        if(row - 1 >= 0 && row - 1 != check[count-1].second)
        {
            FindMaxValue(col, row - 1, cur_value + arr[col][row-1],count+1,check);
        }
        
        // 세번째는 3방향 가능 및 대각선 가능
        if(count == 3)
        {
            pair<int,int> tempPos = PairMinus(check[count], check[count-1]);

            if(tempPos.first != 0)
            {
                if(row + 1 < M && check[count-2].second != row+1)
                {
                    FindMaxValue(check[count-1].first, row + 1, cur_value + arr[check[count-1].first][row+1],count+1,check);
                }
                if(row - 1 >= 0 && check[count-2].second != row-1)
                {
                    FindMaxValue(check[count-1].first, row - 1, cur_value + arr[check[count-1].first][row-1],count+1,check);
                }
            }
            else
            {
                if(col + 1 < N && check[count-2].first != col+1)
                {
                    FindMaxValue(col + 1, check[count-1].second, cur_value + arr[col+1][check[count-1].second],count+1,check);
                }
                if(col - 1 >= 0 && check[count-2].first != col-1)
                {
                    FindMaxValue(col - 1, check[count-1].second, cur_value + arr[col-1][check[count-1].second],count+1,check);
                }
            }
        }
    }
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    arr = vector< vector<int> >(N,vector<int>(M));
    vector< pair<int,int> > check = vector< pair<int,int> >(4);

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            FindMaxValue(i, j, arr[i][j], 1, check);
        }
    }

    cout << MaxValue << '\n';

    return 0;
}
