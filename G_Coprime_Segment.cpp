// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

struct Node{
    int val;
    int g;
};

struct GCDQ{
    stack<Node> left, right;

    void push(int x){
        int g = right.empty() ? x : gcd(right.top().g, x);
        right.push({x,g});
    }
    void transfer(){
        while(!right.empty()){
            int x = right.top().val;
            right.pop();
            int g = left.empty() ? x : gcd(left.top().g, x);
            left.push({x,g});
        }
    }
    void pop(){
        if(left.empty()) transfer();
        left.pop();
    }
    int getGCD(){
        if(left.empty()) return right.top().g;
        if(right.empty()) return left.top().g;
        return gcd(left.top().g, right.top().g);
    }
    bool empty(){
        return left.empty() && right.empty();
    }
    int size(){
        return left.size() + right.size();
    }
};

void solve()
{
    int n;
    cin >> n ;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    GCDQ q;

    int l=0, ans = INT_MAX;
    for(int r=0; r<n; r++){
        q.push(a[r]);
        while(!q.empty() && q.getGCD() == 1){
            ans = min(ans, q.size());
            q.pop();
        }
    }
    if(ans==INT_MAX) cout<<-1<<'\n';
    else
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