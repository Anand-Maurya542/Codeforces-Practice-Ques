// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

class SegTree{
public:
    vector<int> seg;

    SegTree(int n){
        seg.assign(4*n+1, 0);
    }

    void update(int i, int lo, int hi,int idx, int val){
        if(lo == hi){
            seg[i] = max(seg[i], val);
            return;
        }

        int mid = (lo+hi)/2;

        if( idx <=mid ) update(2*i+1, lo, mid, idx,val);
        else update(2*i+2, mid+1, hi,idx, val);

        seg[i]=max(seg[2*i+1], seg[2*i+2]);
    }

    int query(int i, int l, int r, int start, int end){
        if(l>end || r<start) return 0;
        if(start <= l && r <= end){
            return seg[i];
        }
        int mid = (l+r)/2;

        return max(query(2*i+1, l, mid, start, end), query(2*i+2, mid+1, r, start, end));
    }

};

void solve()
{
    int n;
    cin >> n ;

    vector<int> a(n),h(n);
    for(int &x:h) cin>>x;
    for(int &x:a) cin>>x;

    SegTree st(n);

    int ans = 0;

    for(int i=0; i<n; i++){
        int best_before = 0;

        if(h[i]>1){
            best_before=st.query(0,1,n,1,h[i]-1);
        }

        int curr = a[i] + best_before;

        st.update(0,1,n,h[i],curr);

        ans = max(ans, curr);
    }
    cout<<ans<<"\n";

    
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