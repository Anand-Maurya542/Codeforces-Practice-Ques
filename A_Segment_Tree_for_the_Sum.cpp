#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegTree{
    private:   
        vector<ll> tree;
        vector<ll> arr;
        int n;

        void build(int i, int l , int r){
            if(l==r){
                tree[i]=arr[l];
                return;
            }
            int mid = l + (r-l)/2;
            
            build(2*i+1, l, mid);
            build(2*i+2 , mid+1, r);
            
            tree[i] = tree[2*i+1] + tree[2*i+2]; //merge function
        }
        
        void update(int i, int l, int r , int val, int pos){

            if(l==r){
                tree[i] = val;
                return;
            }
            int mid = l + (r-l)/2;
            
            if(pos <= mid) update(2*i+1, l, mid, val, pos);
            else update(2*i+2, mid + 1, r, val, pos);

            tree[i]=tree[2*i+1] + tree[2*i+2];
        }

        ll query(int i, int l , int r, int ql, int qr){
            if(l > qr || r < ql) return 0;

            if(ql <= l && r <= qr) return tree[i]; //within range

            int mid = l + (r-l)/2;
            
            return query(2*i+1, l, mid, ql, qr ) + query(2*i+2, mid + 1, r, ql, qr );
        }
    
    public :
        SegTree(vector<ll>& nums){
            arr = nums;
            n = arr.size();
            tree.resize(4*n);
            build(0, 0, n-1);
        }

        ll getSum(int l, int r){
            return query(0,0,n-1, l, r);
        }
        void setValue(int val, int pos){
            update(0,0,n-1, val, pos);
        }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<ll> nums(n);
    for(ll& x : nums) cin>>x;
    SegTree st(nums);

    for(int i=0; i<m; i++){
        int o, a, b;
        cin>>o>>a>>b;
        if(o == 1){
            st.setValue(b,a);

        }else{
            cout<<st.getSum(a,b-1)<<"\n";
        }
    }
}