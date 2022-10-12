// 뒤집기

#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;

    char prev = S[0];
    int count = 1;
    for(int i = 1; i<S.size(); i++)
    {
        if(S[i] != prev)
        {
            count += 1;
            prev = S[i];
        }
    }

    cout << count / 2 << '\n';

    return 0;
}
