#include<stdio.h>
void bin(int n){
    long long int x=0;int mul=1;
    while(n){
        //x=n%2;
        x+=(n%2)*mul;
        n=n/2;
        mul*=10;
    }
    printf("%lld",x);
}
void oct(int n){
     int x=0;int mul=1;
    while(n){
        x=x+(n%8)*mul;
        n/=8;
      mul*=10;
    }
    printf("%d",x);
}
int main(){
    int n;
    int m;
    int x;

    printf("type 1 for binary 2 for octal\n");
    scanf("%d",&x);
    switch(x){
        case 1: 
        printf("ENter the number\n");
        scanf("%d",&n);
        bin(n);
       // break;
        case 2:
        printf("ENter the number\n");
        scanf("%d",&m);
        oct(m);
    }
}