// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
struct Node{
    int ti;
    int ballons;
    int rest;
};

vector<Node> worker;
int n, m;

bool valid(int T){
    int total = 0;

    for(auto [t,z,y] : worker){
        int full = t * z + y;
        int cycles = T/full;
        total += cycles * z;
        int rem = T % full;
        total += min(z, rem/t);

    }
    return total >= m;
}

int canMake(int t, int z, int y, int T){
    int total = 0;
    int full = t * z + y;
        int cycles = T/full;
        total += cycles * z;
        int rem = T % full;
        total += min(z, rem/t);
    return total;
}

void solve()
{   
    worker.clear();
    cin >> m >> n;
    for(int i=0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        worker.push_back({a,b,c});
    }

    int lo = 0, hi = 1e9;
    int ans;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(valid(mid)){
            ans=mid;
            hi=mid-1;
        }else lo=mid+1;
    }
    cout<<ans<<'\n';

    int left = m;

    for(auto [t,z,y] : worker){
        int capacity = canMake(t,z,y,ans);
        cout<<min(left, capacity)<<' ';
        left -= capacity;
        if(left<0) left = 0;
    }
    cout<<'\n';
    
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}