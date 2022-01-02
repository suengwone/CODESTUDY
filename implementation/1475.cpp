// 방 번호

#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N;
    scanf("%d",&N);
    vector<int> arr(10,0);
    
    int temp = N;
    
    while(temp != 0){
        int num = temp % 10;
        temp /= 10;
        arr[num] += 1;
    }
    
    int num69 = arr[6]+arr[9];
    
    if((num69) % 2 == 1){
        arr[6] = num69 / 2 + 1;
        arr[9] = num69 / 2;
    } else {
        arr[6] = num69/2;
        arr[9] = num69/2;
    }
    
    int max_count=0;
    
    for(int i=0;i<10;i++){
        if(arr[i]>max_count){
            max_count = arr[i];
        }
    }
    
    printf("%d\n",max_count);
}
