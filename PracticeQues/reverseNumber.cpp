#include <bits/stdc++.h>
using namespace std;
int main(){
    int x=12345;
    int last_digit=0;
    int revNum=0;
    while (x>0)
    {
        last_digit=x%10;
        revNum=revNum*10+last_digit;
        x=x/10;
    }
    cout<<revNum;
    
    return 0;
}