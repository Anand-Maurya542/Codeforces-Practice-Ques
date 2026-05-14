#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &x:a) cin>>x;

        
        bool flag=false;
        for(int i=0; i<n; i++){
             for(int j=i+1; j<n; j++){
                if(__gcd(a[i], a[j])<=2){
                    cout<<"Yes"<<"\n";
                    flag=true;
                    break;
                }
             }
             if(flag) break;
        }
        if(!flag) cout<<"No"<<"\n";
    }
}