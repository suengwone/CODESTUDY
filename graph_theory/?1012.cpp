// 유기농 배추

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> point;

bool CheckPoint(point _point, int** _field, int** _check)
{
    if(_check[_point.first][_point.second] == false && _field[_point.first][_point.second] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int T, M, N, K, row, col;

    cin>>T;

    while(T--)
    {
        cin>>M>>N>>K;

        int** field = new int*[N];
        for(int i=0;i<N;i++)
        {
            field[i] = new int[M];
        }
        
        bool** check = new bool*[N];
        for(int i=0;i<N;i++)
        {
            check[i] = new bool[M];
        }

        for(int i=0;i<K;i++)
        {
            cin>>row>>col;
            field[row][col] = 1;
        }

        queue<point> nearPoints;

        for(int i=0; i<M; i++)
        {
            for(int j=0;j<N;j++)
            {
                if(CheckPoint(point(i,j), &field, &check))
                {
                    nearPoints.push(point(i,j));
                    while(nearPoints.empty() != true)
                    {
                        point temp = nearPoints.front();
                        nearPoints.pop();
                    }
                }
            }
        }
    }
}

// 23.3.12
#include <iostream>
#include <memory.h>

using namespace std;

bool check[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int field[51][51];
int M,N,K;

void DFS(int x, int y)
{
    check[x][y] = true;
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < N && ny >= 0 && ny < M)
        {
            if(field[nx][ny] == 1 && check[nx][ny] == false)
            {
                DFS(nx,ny);
            }
        }
    }
}

int main()
{
    int T;

    cin >> T;

    while(T--)
    {
        cin >> M >> N >> K;

        int x, y, count = 0;

        for(int i=0; i<K; i++)
        {
            cin >> x >> y;
            field[y][x] = 1;
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(field[i][j] == 1 && check[i][j] == false)
                {
                    count += 1;
                    DFS(i,j);
                }
            }
        }
        
        cout << count << '\n';

        memset(check,false,sizeof(check));
        memset(field,0, sizeof(field));
    }
}
