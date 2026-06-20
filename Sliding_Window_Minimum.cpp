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
    
    int x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<int> v(n);
    v[0]=x;

    for(int i=1; i<n; i++){
        v[i]=(v[i-1]*a + b)%c;
    }
    
    vector<int> res;
    deque<int> dq;

    for(int i=0; i<n; i++){
        //remove

        if(!dq.empty() && dq.front() <= i-k) dq.pop_front();

        //maintain increasing order
        while(!dq.empty() && v[i] <= v[dq.back()] ) dq.pop_back();

        dq.push_back(i);

        if(i+1 >= k){
            res.push_back(v[dq.front()]);
        }


    }
    int ans=0;
    for(int& x : res){

        ans^=x;
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