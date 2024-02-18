// 내리막 길
#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int M, N;

class PointInfo
{
public:
    int count;
    int value;

    PointInfo()
    {
        this->count = -1;
    }
};

vector<vector<PointInfo>> map;

int DFS(int col, int row)
{
    if(col == M - 1 && row == N - 1)
        return 1;

    if(map[col][row].count == -1)
    {
        map[col][row].count = 0;

        for(int i=0; i<4; i++)
        {
            int moveCol = col + dx[i];
            int moveRow = row + dy[i];

            if(moveCol >= 0 && moveCol < M && moveRow >= 0 && moveRow < N)
            {
                if(map[moveCol][moveRow].value < map[col][row].value)
                    map[col][row].count += DFS(moveCol, moveRow); 
            }
        }
    }

    return map[col][row].count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> M >> N;

    map.assign(M, vector<PointInfo>(N));

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j].value;
        }
    }

    cout << DFS(0,0) << '\n';

    return 0;
}
