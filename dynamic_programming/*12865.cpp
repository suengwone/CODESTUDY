// 평범한 배낭

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> object;


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    vector<object> objectList;

    cin >> N >> K;

    for(int i=0; i<N; i++)
    {
        object singleObj;
        cin >> singleObj.first >> singleObj.second;

        objectList.push_back(singleObj);
    }

    sort(objectList.begin(), objectList.end(), [] (object a, object b) 
    {
        if(a.first == b.first)
            return a.second < b.second;
        else
            return a.first < b.first;
    });

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= objectList[i - 1].first)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - objectList[i - 1].first] + objectList[i - 1].second);
            }
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}
