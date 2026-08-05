#include <bits/stdc++.h>
using namespace std;

class SegTree{

    private:

    vector<int> tree;
    vector<int> arr;
    int n;

    void update(int i, int pos,int val, int l, int r){
        if(l==r){
            tree[i]=val;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(2*i+1, pos, val, l,mid);
        else update(2*i+2, pos, val, mid+1, r);

        tree[i]=tree[2*i+1] + tree[2*i+2];

    }
    int query(int i, int l, int r, int start, int end){
        if(l>end || r < start) return 0;
        if(start<=l && r<=end) return tree[i];
        int mid = (l+r)/2;

        return query(2*i+1, l, mid, start, end) + query(2*i+2, mid+1, r, start, end);
    }

    public:
        SegTree(int n, vector<int> v){
            this->n = n;
            arr = v;
            tree.assign(4*n,0);

        }
        int get(int idx, int start, int end){
            int val = query(0,0,n, start, end);
            update(0,idx, 1, 0, n);
            return val;
        }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int& x : arr) cin>>x;

    SegTree st(n, arr);

    for(int i=0; i<n; i++){
        int ans = st.get(arr[i], arr[i]+1, n);
        cout<<ans<<' ';
    }
    cout<<'\n';

}