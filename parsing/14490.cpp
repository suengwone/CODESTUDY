// 백대열

#include <iostream>

using namespace std;

int gcd(int n, int m){
    if(m==0)
        return n;
    else
        return gcd(m,n%m);
}

int main(void){
    int n,m,temp;
    scanf("%d:%d",&n,&m);
    
    temp = gcd(n,m);
    
    printf("%d:%d\n",n/temp,m/temp);
}
