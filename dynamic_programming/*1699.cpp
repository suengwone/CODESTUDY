// 제곱수의 합

#include <iostream>
#include <vector>

using namespace std;

int DP(int N)
{
    vector<int> memo(N+1, N);
    memo[0] = 0;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j*j <= i; j++)
        {
            memo[i] = min(memo[i], memo[i - j*j] + 1);
        }
    }

    return memo[N];
}

int main()
{
    int N;
    cin >> N;

    cout << DP(N) << '\n';

    return 0;
}
