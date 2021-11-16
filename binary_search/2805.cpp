// 나무 자르기

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N, M, H = 0;
    sacnf("%d %d", &N, &M);

    vector<int> tree_list(N);
    for(int i=0; i<N; i++) {
        scanf("%d",&tree_list[i]);
    }

    int left = 0, right = N;

    sort(tree_list.begin(),tree_list.end());

    while(left <= right) {
        int mid = (left + right) / 2;
        if(/*자르고 나은 길이의 합*/ > M)
            right = mid - 1;
        else if(/*자르고 나은 길이의 합*/ < M)
            left = mid + 1;
        else {
            H = mid;
            break;
        }
    }

    // 처음일때와 끝일때는 일반적인 케이스가 아니기 때문에 따로 처리해준다

    printf("%d\n",H);
}
