#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;cin>>n;
    int two=0;
    vector<int> a(n);
    for(auto&x:a){
        cin>>x;
        if(x==2) two++;
    }
   
    if(two&1){
        cout<<-1<<'\n';
    }else{
        for(int i=0; i<n; i++){
            if(a[i]==2) two-=2;
            if(two==0){                
                cout<<i+1<<'\n';
                break;
            }
        }
    }

    }
}