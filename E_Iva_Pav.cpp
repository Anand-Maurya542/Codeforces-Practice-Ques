// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
// #define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int pre[32][200005]; //stores count of unset bit

bool valid(int l, int r, int k){
    int ans = 0;
    for(int i=0; i<30; i++){
        int cnt = pre[i][r+1]-pre[i][l];
        if(cnt == 0) ans|=(1<<i);
    }
    return ans >= k;

}

void solve()
{
    int n;
    cin >> n ;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    for(int i=0; i<30; i++){
        pre[i][0]=0;
        for(int j=0; j<n; j++){
            if((1<<i) & a[j]){
                pre[i][j+1] = pre[i][j];
            }else{
                pre[i][j+1]=pre[i][j]+1;
            }
        }
    }

    int q;
    cin>>q;
    while(q--){

        int l,k;
        cin>>l>>k;
        l--;

        int lo=l, hi=n-1;
        int ans = -1;

        if(a[l] < k){
            cout<<-1<<' ';
            continue;
        }

        while(lo<=hi){
            int mid = (lo+hi)/2;

            if(valid(l,mid,k)){
                ans = mid;
                lo=mid+1;
            }else hi=mid-1;

        }
        cout<<ans+1<<' ';
    }
    cout<<'\n';
    
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