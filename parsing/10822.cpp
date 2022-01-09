// 더하기

#include <iostream>
#include <cstring>

using namespace std;

char word[100];

int main(void){
    int result = 0;
    scanf("%s",&word);
    
    char *temp = strtok(word, ",");
    
    while(temp != NULL){
        int num = stoi(temp);
        result += num;
        temp = strtok(NULL, ",");
    }
    
    printf("%d\n",result);
}
