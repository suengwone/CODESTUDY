// 랜선 자르기

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
