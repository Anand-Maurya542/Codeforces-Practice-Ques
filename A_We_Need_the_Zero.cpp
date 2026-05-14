#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ans=0;
        int k=n;
        while(k--){
            int x; cin>>x;
            //  cout<<x<<' ';
            ans^=x;
        }
        if(n%2==0){
            if(ans==0){
                cout<<0<<'\n';
                continue;
            }else{
                cout<<-1<<'\n';
                continue;
            }
        }
        // cout<<'\n';
        bool flag=false;
        for(int i=0; i<pow(2,8); i++){
            ans^=i;
            if(ans==0){
                cout<<i<<'\n';
                flag=true;
                break;
            }
            ans^=i;
        }
        if(!flag) cout<<-1<<'\n';
    }
}