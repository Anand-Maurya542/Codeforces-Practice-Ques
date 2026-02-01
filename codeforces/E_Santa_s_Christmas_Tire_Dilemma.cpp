#include <iostream>
using namespace std;

void solve(){
    long long n,mini=0,maxi=0;
    cin>>n;
    if(n%4){
        cout<<-1<<"\n";
        return;        
    }
    else if(n%6){
        cout<<-1<<"\n";
        return; 
    }
    if(n%6==0)
    mini=n/6;
    else if(n%4==0)
    mini=n/4;

    if(n%4==0)
    maxi=n/4;
    else if(n%6==0)
    maxi=n/6;
    cout<<mini<<" "<<maxi<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}