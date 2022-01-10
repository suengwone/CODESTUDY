// 행복한지 슬픈지

#include <iostream>
#include <cstring>

using namespace std;

char word[255];

int main(void){
    int happy=0, sad=0;
    
    cin.getline(word,255);
    
    for(int i=0;i<strlen(word);i++){
        if(word[i] == ':'){
            if(i+2 >= strlen(word))
                break;
            else if(word[i+2] == ')')
                happy+=1;
            else if(word[i+2] == '(')
                sad+=1;
        }
    }
    
    if(happy == 0 && sad == 0){
        cout<<"none\n";
    } else if(happy == sad){
        cout<<"unsure\n";
    } else if(happy > sad){
        cout<<"happy\n";
    } else {
        cout<<"sad\n";
    }
}
