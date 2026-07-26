// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
vector<int> seen;
vector<int> path;
vector<vector<pair<int,int>>> adj;

void dfs(int u){
    while(!adj[u].empty()){

        auto [v,e] = adj[u].back();
        adj[u].pop_back();

        if(seen[e]) continue;

        seen[e]=1;
        dfs(v);

    }
    path.push_back(u);
}


void solve()
{
    int n, m;
    cin >> n >> m;
    
    path.clear();
    seen.assign(m,0); // edges

    adj.resize(n+1);

    vector<int> in(n+1,0);
    vector<int> out(n+1,0);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        out[u]++;
        in[v]++;
    }

    int cnt = 0;

    for(int i=1; i<=n; i++){
        if(in[i]==out[i]) cnt++;
    }
    if(out[1]-in[1]!=1 || in[n]-out[n]!=1 || cnt!=n-2){
        cout<<"IMPOSSIBLE"<<'\n';
        return;
    }


    stack<int> st;
    st.push(1);
    while(!st.empty()){
        int u = st.top();
        if(!adj[u].empty()){
            auto [v,e] = adj[u].back();
            adj[u].pop_back();
            st.push(v);
        }else{
            path.push_back(u);
            st.pop();
        }
    }
    if (path.size() != m + 1) {
    cout << "IMPOSSIBLE\n";
    return;
}

   
    for(int i=path.size()-1; i>=0; i--){
        cout<<path[i]<<' ';
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