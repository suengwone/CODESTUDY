// 수 찾기

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N,M;

    scanf("%d",&N);

    vector<int> N_arr(N);

    for(int i=0;i<N;i++){
        scanf("%d",&N_arr[i]);
    }

    scanf("%d",&M);

    vector<int> M_arr(M);

    for(int i=0;i<M;i++){
        scanf("%d",&M_arr[i]);
    }

    sort(N_arr.begin(),N_arr.end());

    for(int i=0;i<M;i++){
        int find_index = N_arr.size()/2, find_value = M_arr[i], cur_value = N_arr[find_index], prev_index = -1;
        bool answer = true;

        while(find_value != cur_value){
            if(find_index == (N_arr.size() - 1) || find_index == 0 || find_index == prev_index) {
                answer = false;
                break;
            }

            if(find_value > cur_value){
                if(prev_index == -1) prev_index = N_arr.size();
                find_index = (find_index + prev_index) / 2;
            }
            else if (find_value < cur_value) {
                if(prev_index == -1) prev_index = 0;
                find_index = (find_index + prev_index) / 2;
            }
            cur_value = N_arr[find_index];
            prev_index = find_index;
        }

        answer ? printf("1\n") : printf("0\n");
    }
}
