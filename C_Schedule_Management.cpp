// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
int n, m;
vector<int> load;
//1,2,1,2
bool valid(vector<int>& a, int t){
    int need=0, help=0;
    for(int i=1; i<=n; i++){
        if(load[i] > t){
            need += load[i] - t;
        }else help += (t-load[i])/2;
    }
    return help >= need;
}

void solve()
{
    cin >> n >> m;
    vector<int> a(m);
    load.assign(n+1,0);
    for (int &x : a){
        cin >> x;
        load[x]++;
    }
    

    int lo = 0, hi = 2 * m;
    int ans = 0;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(valid(a, mid)){
            ans = mid;
            hi=mid-1;
        }else lo=mid+1;
    }
    cout<<ans<<'\n';
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