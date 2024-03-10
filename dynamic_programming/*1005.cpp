// ACM Craft

#include <iostream>
#include <vector>

using namespace std;

vector<int> buildTime;
vector<vector<int>> buildTree;
vector<int> dp;

int DFS(int curIdx)
{
    if(dp[curIdx] != -1)
        return dp[curIdx];

    int maxValue = 0;
    for(int i=0; i<buildTree[curIdx].size(); i++)
    {
        int nextIdx = buildTree[curIdx][i];
        maxValue = max(maxValue, DFS(nextIdx));
    }

    dp[curIdx] = maxValue + buildTime[curIdx];
    return dp[curIdx];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int T, N, K;
    cin >> T;

    while(T--)
    {
        cin >> N >> K;
        
        buildTime.clear();
        buildTree.clear();
        dp.clear();

        buildTime.assign(N+1, 0);
        buildTree.assign(N+1, vector<int>());
        dp.assign(N+1, -1);

        for(int i=1; i<=N; i++)
        {
            cin >> buildTime[i];
        }

        for(int i=0; i<K; i++)
        {
            int first, second;
            cin >> first >> second;
            buildTree[second].push_back(first);
        }


        int W;

        cin >> W;

        cout << DFS(W) << '\n';
    }

    return 0;
}
