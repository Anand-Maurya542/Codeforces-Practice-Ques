#include <bits/stdc++.h>
using namespace std;
int main(){
    int num=1234,count=0;
    int temp=num;
    int last=0,first=0;
    last=num%10;
    cout<<last<<endl;
    cout<<num<<endl;
    while (temp>0)
    {
        count++;
        temp=temp/10;
    }
    last=last*pow(10,count-1);
    cout<<last<<endl;
    int rem=pow(10,count-1);
     first=num/rem;
     cout<<first<<endl;
     num=num/10;
    int mpart=num%rem;
    cout<<mpart<<endl;
    last=last+mpart+first;
    cout<<last;
    

    return 0;
}