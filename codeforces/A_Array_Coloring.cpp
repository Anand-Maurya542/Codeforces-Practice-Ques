#include <bits/stdc++.h>
using namespace std;

template <typename T>
void read(vector<T>& v){
    for(auto& x:v) cin>>x;
}


void solve(){
    int n;
    cin>>n;
    vector<int> v(n); 
    int odd=0,even=0;
    for(int i=0; i<n ; i++){
        int x; cin>>x;
        if(x&1) odd++;
        else even++;
    }
    if(even && odd%2==0){
        cout<<"YES"<<"\n";
    }else if(odd%2==0) cout<<"YES"<< '\n';
    else cout<<"NO"<<"\n";



}
int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

