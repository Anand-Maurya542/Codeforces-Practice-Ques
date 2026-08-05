// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
using T = tuple<int,int,int>;


void solve()
{
    int n;
    cin >> n ;
    vector<T> a;
    vector<int> last;
    for(int i=0; i<n; i++){
        int x, h;
        cin>>x>>h;
        a.push_back({x,h,i});
        last.push_back(i);
    }

    sort(a.begin(), a.end());

    for(int i=n-1; i>=0; i--){
        auto& [xi,hi,id] = a[i]; 
        int minR = xi;
        int maxR = xi+hi-1;

        int maxId = i;
        for(int j=i+1; j<n; j++){
            auto& [xj, hj, idj] = a[j];
            if(xj>maxR) break;
            maxId = max(maxId, last[j]);//higest value in that range

        }
        last[i] = maxId;
    }

    vector<int> ans(n);
    for(int i=0; i<n; i++){
        ans[get<2>(a[i])] = last[i] - i + 1;
    }
    for(int& x : ans){
        cout<<x<<' ';
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