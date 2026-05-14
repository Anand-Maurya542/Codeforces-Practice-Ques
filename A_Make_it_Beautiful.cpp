#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(auto &x:a) cin>>x;
        sort(a.begin(), a.end());
        if(a[0]==a[n-1]){
            cout<<"NO"<<'\n';
        }else{
            swap(a[0],a[1]);
            swap(a[0],a[n-1]);
            cout<<"YES"<<"\n";
            for(auto &x:a){
                cout<<x<<" ";
            }
            cout<<'\n';
        }
    }
}