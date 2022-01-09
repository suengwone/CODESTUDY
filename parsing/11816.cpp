//8진수, 10진수, 16진수

#include <iostream>
#include <cstring>

using namespace std;

char Num[10];

int main(void){
    int result = 0, multiple = 1;
    scanf("%s",&Num);
    int size = strlen(Num);
    
    if(Num[0]!='0' || size == 1){
        printf("%s\n",Num);
    } else if(Num[1]!='x'){
        for(int i= size - 1; i>=1; i--){
            result += (Num[i] - '0')*multiple;
            multiple *= 8;
        }
        printf("%d\n",result);
    } else{
        for(int i= size - 1; i>=2;i--){
            result += (Num[i] - '0' >= 10 ? Num[i] - 87 : Num[i] - '0') * multiple;
            multiple *= 16;
        }
        printf("%d\n",result);
    }
}
