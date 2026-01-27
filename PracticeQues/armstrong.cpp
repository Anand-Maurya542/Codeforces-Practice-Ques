#include <iostream>
using namespace std;
int main(){

    // concept of armstrong is power to the total number of digits . 
    int x;
    cin>>x;
    int num=x;
    int sum=0,ld;
    while (x>0)     
    {
        ld=x%10;
        sum+=ld*ld*ld;
        x=x/10;
    }
    if(sum==num){
        cout<<"Armstrong";
    }
    else cout<<"Not armstrong";
    
    return 0;
}