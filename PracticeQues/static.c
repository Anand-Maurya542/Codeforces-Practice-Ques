#include<stdio.h>
void stat(){
    static int x=9;
    printf("%d\t",x);
    x++;
}
int main(){
    int a=9;
    while(a--)
    stat();

}