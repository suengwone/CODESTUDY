// 합분해

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp(K+1, vector<int>(N+1, 1));

    for(int i=2; i<=K; i++)
    {
        for(int j=1; j<=N; j++)
        {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
        }
    }

    cout << dp[K][N] << '\n';

    return 0;
}
