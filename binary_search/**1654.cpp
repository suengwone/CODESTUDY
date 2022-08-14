// 랜선 자르기 첫번째 풀이

#include <iostream>

using namespace std;

int K, N, answer;
int line[10001];
int _max = 0;
long long mid, high, low;

int main(void){
    scanf("%d %d",&K,&N);

    for(int i=0; i < K; i++){
        scanf("%d",&line[i]);
        if(_max < line[i])
            _max = line[i];
    }
    low = 1;
    high = _max;
    answer = 0;

    while(low <= high){
        mid = (low + high) / 2;
        int cnt = 0;
        for(int i=0; i < K; i++)
            cnt += line[i] / mid;

        if(cnt >= N) {
            low = mid + 1;
            if(answer < mid)
                answer = mid;
        } else {
            high = mid - 1;
        }
    }
    
    printf("%d\n",answer);
}


// 랜선 자르기 두번째 풀이 - 재귀

vector<int> LanList;
int K, N;

long long low,high;


long long CheckCount(long long length, long long answer)
{
    if(length == 0)
    {
        return CheckCount(1,answer);
    }

    int count = 0;
    for(int i = 0; i < LanList.size(); i++)
    {
        count += LanList[i]/length;
    }

    if(low > high)
    {
        return length;
    }
    else
    {
        if(count >= N)
        {
            low = length + 1;
            if(answer < length)
            {
                answer = length;
            }
        }
        else
        {
            high = length - 1;
        }
    }

    return CheckCount((low+high)/2, answer < length ? length : answer);
}


int main()
{
    cin>> K >> N;

    LanList = vector<int>(K);
    low = 0;

    for(int i=0; i<K; i++)
    {
        cin >> LanList[i];
        if(high < LanList[i])
        {
            high = LanList[i];
        }
    }

    cout << CheckCount((low + high)/2, 0) <<'\n';

    return 0;
}
