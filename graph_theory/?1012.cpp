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
