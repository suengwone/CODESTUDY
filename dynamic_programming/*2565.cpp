// 전깃줄

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Connection;

bool Compare(Connection a, Connection b)
{
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N;
    cin >> N;
    vector<Connection> lines(N);

    for(int i=0; i<N; i++)
    {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end(), Compare);
    
    vector<int> lis(N, 1);
    int maxLIS = 1;

    for(int i=1; i<N; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(lines[i].second > lines[j].second)
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        maxLIS = max(maxLIS, lis[i]);
    }

    cout << N - maxLIS << '\n';

    return 0;
}
