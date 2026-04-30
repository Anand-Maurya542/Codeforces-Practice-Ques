#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        if(n%k!=0){
            cout<<1<<'\n';
            cout<<n<<'\n';
        }else{
            cout<<2<<'\n';
            cout<<n-k-1<<' '<<k+1<<'\n';
        }
    }
}