#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int s=n;
        while(s--){
            int x;
            cin>>x;
            cout<<n+1-x<<' ';
        }
        cout<<'\n';
    }
}