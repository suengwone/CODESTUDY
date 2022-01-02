// 요세푸스 문제 0

#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N,K, cur_index = 0;
    scanf("%d %d",&N,&K);
    
    vector<int> arr(N), answer;
    
    for(int i=0;i<N;i++){
        arr[i] = i+1;
    }
    
    int count;
    while(answer.size() != N){
        count = 1;
        while(true){
            if(cur_index == arr.size()){
                cur_index = 0;
            }
            
            if(count == K){
                answer.push_back(arr[cur_index]);
                arr.erase(arr.begin()+cur_index);
                break;
            }
            cur_index += 1;
            count += 1;
        }
    }
    
    printf("<");
    for(int i=0;i<N;i++){
        printf("%d", answer[i]);
        if(i != N-1){
            printf(", ");
        } else {
            printf(">\n");
        }
    }
}
