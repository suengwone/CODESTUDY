// 계단 오르기

#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> step_value_list;

int FindMaxValue()
{
    vector<int> list_cpy = step_value_list;

    list_cpy[1] += step_value_list[0];
    list_cpy[2] += max(step_value_list[0], step_value_list[1]);

    for(int i=3; i<N; i++)
    {
        list_cpy[i] += max(list_cpy[i-2], step_value_list[i-1] + list_cpy[i-3]);
    }

    return list_cpy[N-1];
}

int main()
{
    cin >> N;

    step_value_list.resize(N);

    for(int i=0; i<N; i++)
    {
        cin >> step_value_list[i];
    }

    cout<< FindMaxValue() << '\n';

    return 0;
}
