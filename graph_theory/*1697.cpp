// 숨바꼭질

#include <iostream>
#include <queue>

using namespace std;

int K;
bool check[100001] = {false};

bool IsValid(int _checkNum)
{
    if(_checkNum < 0 || _checkNum > 100000 || check[_checkNum])
    {
        return false;
    }
    else
    {
        return true;
    }
}

int CalcTime(queue<pair<int,int>> _remainNumQue)
{
    int data, depth;

    while(_remainNumQue.empty() != true)
    {
        data = _remainNumQue.front().first;
        depth = _remainNumQue.front().second;
        _remainNumQue.pop();

        if(data == K)
        {
            return depth;
        }

        if(IsValid(data - 1))
        {
            check[data-1] = true;
            _remainNumQue.push(pair(data-1, depth + 1));
        }

        if(IsValid(data + 1))
        {
            check[data+1] = true;
            _remainNumQue.push(pair(data+1, depth + 1));
        }

        if(IsValid(data * 2))
        {
            check[data*2] = true;
            _remainNumQue.push(pair(data*2, depth + 1));
        }
    }

    return depth;
}

int main()
{
    int N;

    cin>>N>>K;

    queue<pair<int,int>> remainNumQue;
    remainNumQue.push(pair(N,0));
    check[N] = true;

    cout << CalcTime(remainNumQue) << '\n';

    return 0;
}
