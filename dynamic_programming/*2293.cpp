// 동전 1

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

    sort(coinList.begin(), coinList.end(), [] (int a, int b) { return a < b;});

    vector<int> dp(K + 1, 0);
    dp[0] = 1;

    for(int i=0; i<N; i++)
    {
        for(int j=coinList[i]; j<=K; j++)
        {
            dp[j] += dp[j - coinList[i]];
        }
    }

    cout << dp[K] << '\n';
 
    return 0;
}
