// RGB 거리

#include <iostream>
#include <vector>

using namespace std;

int N;

class HouseInfo
{
public:
    vector<int> red_arr, green_arr, blue_arr;

    HouseInfo()
    {
        this->red_arr.resize(N);
        this->green_arr.resize(N);
        this->blue_arr.resize(N);
    }

    int FindMinValue()
    {
        vector<int> red_cpy = this->red_arr;
        vector<int> green_cpy = this->green_arr;
        vector<int> blue_cpy = this->blue_arr;

        for(int i=1; i<N; i++)
        {
            red_cpy[i] += min(green_cpy[i-1], blue_cpy[i-1]);
            green_cpy[i] += min(blue_cpy[i-1], red_cpy[i-1]);
            blue_cpy[i] += min(green_cpy[i-1], red_cpy[i-1]);
        }

        return min(red_cpy[N-1], min(green_cpy[N-1],blue_cpy[N-1]));
    }
};

int main()
{
    cin >> N;

    HouseInfo houseInfo;

    for(int i=0; i<N; i++)
    {
        cin >> houseInfo.red_arr[i] >> houseInfo.green_arr[i] >> houseInfo.blue_arr[i];
    }

    cout << houseInfo.FindMinValue() << '\n';

    return 0;
}
