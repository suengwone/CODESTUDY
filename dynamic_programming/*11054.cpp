// 가장 긴 바이토닉 부분 수열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);

    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }

    vector<int> dpInc(N, 1);
    vector<int> dpDec(N, 1);

    for(int i=1; i<N; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[i] > A[j])
            {
                dpInc[i] = max(dpInc[i], dpInc[j] + 1);
            }
        }
    }

    for(int i=N-2; i>=0; i--)
    {
        for(int j=N-1; j>i; j--)
        {
            if(A[i] > A[j])
            {
                dpDec[i] = max(dpDec[i], dpDec[j] + 1);
            }
        }
    }

    int maxLength = 0;

    for(int i=0; i<N; i++)
    {
        maxLength = max(maxLength, dpInc[i] + dpDec[i] - 1);
    }

    cout << maxLength << '\n';

    return 0;
}
