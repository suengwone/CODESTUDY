// 숨바꼭질

#include <iostream>
#include <vector>

using namespace std;

int totalCount = 100001;
int K;

void CalcTime(int _count, int _num, vector<bool> _check)
{
    if(_count >= totalCount || _num > 100000 || _check[_num] == true)
    {
        return;
    }

    _check[_num] = true;

    if(_num == K)
    {
        if(totalCount > _count)
        {
            totalCount = _count;
        }
        
        return;
    }
    else if(_num > K)
    {
        if(totalCount > _count + (_num - K))
        {
            totalCount = _count + (_num - K);
        }

        return;
    }

    if(_num > 0)
    {
        CalcTime(_count+1, _num * 2, _check);
        CalcTime(_count+1, _num - 1, _check);
    }

    CalcTime(_count+1, _num + 1, _check);

    return;
}

int main()
{
    int N;

    cin>>N>>K;

    vector<bool> check(K * 2, false);

    CalcTime(0, N, check);

    cout << totalCount << '\n';

    return 0;
}
