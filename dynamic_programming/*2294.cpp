// 동전 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;

    vector<int> coinList(N);

    for(int i=0; i<N; i++)
    {
        cin >> coinList[i];
    }

    vector<int> dp(K+1, K + 1);
    dp[0] = 0;

    for(int i=0; i<N; i++)
    {
        for(int j=coinList[i]; j<=K; j++)
        {
            dp[j] = min(dp[j], dp[j - coinList[i]] + 1);
        }
    }

    dp[K] = dp[K] == K + 1 ? -1 : dp[K];

    cout << dp[K] << '\n';

    return 0;
}
