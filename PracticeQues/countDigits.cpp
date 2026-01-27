#include <bits/stdc++.h>
using namespace std;
int main(){
    int x=165463;
    int cnt=0;
    while (x>0)
    {
        cnt++;
        x=x/10;
    }
    cout<<"digits are : "<<cnt<<endl;
    
    return 0;
}