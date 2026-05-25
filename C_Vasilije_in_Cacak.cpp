#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        long long n,k;
        long long x, sum=0;
        cin>>n>>k>>x;

        long long total = n*(n+1)/2;
        
        long long n_k = total - (n-k)*(n-k+1)/2;
        long long sum_k = k*(k+1)/2;

        if(sum_k <=x && x<= n_k ) cout<<"YES"<<"\n";
        else cout<<"NO"<<'\n';

    }
}