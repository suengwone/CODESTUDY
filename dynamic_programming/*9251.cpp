// LCS

#include <iostream>
#include <vector>

using namespace std;

void LCS(const string &str1, const string &str2)
{
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(str1[i] == str2[j])
            {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else
            {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    cout << dp[m][n] << '\n';
}

int main()
{
    string first, second;

    cin >> first >> second;

    LCS(first, second);

    return 0;
}

// 출처 : https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence
