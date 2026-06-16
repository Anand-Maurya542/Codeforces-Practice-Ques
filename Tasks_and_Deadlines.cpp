// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> duration(n), deadline(n);
    for(int i=0; i<n; i++){
        int d, dl;
        cin>>d>>dl;
        duration[i]=d;
        deadline[i]=dl;
    }
    int curr_time = 0;

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j){
        return duration[i] < duration[j];
    });

    curr_time = duration[order[0]];
    int reward = deadline[order[0]] - curr_time;

    for(int i=1; i<n; i++){
        int idx = order[i];

        curr_time += duration[idx];
        reward += deadline[idx] - curr_time;
    }

    cout<<reward<<'\n';
    
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