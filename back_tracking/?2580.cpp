// 스도쿠

#include <iostream>
#include <vector>

using namespace std;

int sdokuBoard[9][9];
vector< pair<int,int> > problem;
int cnt;
bool found = false;

bool Check(int x, int y)
{
    for(int i=0; i<9; i++)
    {
        if(sdokuBoard[x][i] == sdokuBoard[x][y] && i != y)
        {
            return false;
        }
        if(sdokuBoard[i][y] == sdokuBoard[x][y] && i != x)
        {
            return false;
        }
    }

    int square_x = x / 3, square_y = y / 3;
    for(int i = square_x * 3; i < square_x * 3 + 3; i++)
    {
        for(int j = square_y * 3; j < square_y * 3 + 3; j++)
        {
            if(sdokuBoard[i][j] == sdokuBoard[x][y])
            {
                if(i != x || j != y)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void Sdoku(int Num)
{
    if(Num == cnt)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cout<< sdokuBoard[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true;
        return;
    }

    for(int i=1; i<=9; i++)
    {
        sdokuBoard[problem[Num].first][problem[Num].second] = i;
        if(Check(problem[Num].first, problem[Num].second))
        {
            Sdoku(Num+1);
        }
        if(found)
        {
            return;
        }
    }
    
    sdokuBoard[problem[Num].first][problem[Num].second] = 0;
    return;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9;j++)
        {
            cin >> sdokuBoard[i][j];
            if(sdokuBoard[i][j] == 0)
            {
                problem.push_back(pair<int,int>(i,j));
            }
        }
    }

    cnt = problem.size();

    Sdoku(0);

    return 0;
}
