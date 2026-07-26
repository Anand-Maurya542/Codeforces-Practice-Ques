// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

bool valid(vector<int>& cnt, int n, int T){
    
    int help = 0, rem = 0;
    
    for(int i=0; i<n; i++){
        if(cnt[i] > T){
            rem += cnt[i]-T;
        }else{
            help += (T-cnt[i])/2;
        }
    }
    return rem <= help;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> tasks(k);
    vector<int> cnt(n);
    for(int &x:tasks){
        int t; cin>>t;
        x = t-1;
    }
    for(int& x : tasks){
        cnt[x]++;
    }
    int lo = 0, hi = 2 * k;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(valid(cnt, n, mid)){
            hi = mid-1;
        }else lo=mid+1;
    }
    cout<<lo<<'\n';
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}