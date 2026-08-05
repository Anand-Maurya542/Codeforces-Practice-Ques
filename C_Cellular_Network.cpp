// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> city(n),tower(k) ;

    for(int &x:city) cin>>x;
    for(int &x:tower) cin>>x;

    sort(city.begin(), city.end());
    sort(tower.begin(), tower.end());


    int ans = LLONG_MIN;

    int i = 0, j = 0;
    for(int& c : city){
        while(j+1<k && abs(tower[j+1]-c) <= abs(tower[j]-c)) j++;
        ans = max(ans, abs(tower[j]-c));
    }
    cout<<ans<<'\n';





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