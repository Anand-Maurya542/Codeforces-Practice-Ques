// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

class SegTree{
    vector<int> tree,arr;
    int n;

    void build(int i, int l, int r){
        if(l==r){
            tree[i]=1;
            return;

        }

        int mid = (l+r)/2;

        build(2*i+1, l,mid);
        build(2*i+2, mid+1, r);

        tree[i]=tree[2*i+1]+tree[2*i+2];
    }

    void update(int i, int l, int r, int k){
        if(l==r){
            tree[i]=0;
            return;
        }
        int mid = (l+r)/2;

        if(k <= tree[2*i+1]){
            update(2*i+1, l, mid, k);
        }else update(2*i+2, mid+1, r , k - tree[2*i+1]);

        tree[i]=tree[2*i+1]+tree[2*i+2];
    }

    int query(int i, int l, int r, int k){
        if(l==r){
            return arr[l];
        }
        int mid = (l+r)/2;

        if(k <= tree[2*i+1])
            return query(2*i+1, l, mid, k);
        return query(2*i+2, mid+1, r , k - tree[2*i+1]);

    }

    public:
    SegTree(int n, vector<int>& nums){
        this->n = n;
        tree.resize(4*n);
        arr=nums;
        build(0,0,n-1);
    }

    int getElement(int k){
        int ans = query(0,0,n-1,k);
        update(0,0,n-1,k);
        return ans;
    }
};

void solve()
{
    int n;
    cin >> n ;
    vector<int> a(n), ind(n);
    for(int &x:a) cin>>x;
    for(int &x:ind) cin>>x;

    SegTree st(n, a);
    for(int& q : ind){
        cout<<st.getElement(q)<<' ';
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