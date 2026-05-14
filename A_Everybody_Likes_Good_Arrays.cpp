#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int& x:a)cin>>x;
        int cnt=0;
        for(int i=0; i<n-1; i++){
            if( (a[i]&1) == (a[i+1]&1) ) cnt++;
        }
        cout<<cnt<<"\n";
    }
}