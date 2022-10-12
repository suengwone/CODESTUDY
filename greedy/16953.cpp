// A -> B

#include <iostream>

using namespace std;

int main()
{
    unsigned long long int A, B;

    cin >> A >> B;

    int count = 1;
    while(B > A)
    {
        if(B % 2 == 0)
        {
            B /= 2;
        }
        else if(B % 10 == 1)
        {
            B /= 10;
        }
        else
        {
            cout << -1 << '\n';
            return 0;
        }
        count += 1;
    }

    B == A ? cout << count << '\n' : cout << -1 << '\n';

    return 0;
}
