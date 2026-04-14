// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n"; }
template <typename T>
void read(vector<T>& v) { for (auto& x : v) cin >> x; }

template <typename T>
void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

// #define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
// vector<vector<int>>dp;
// vector<int>dp;
//dp.assign(n, vector<int>(m, -1));
//dp.assign(n, -1);
void solve()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int>(n,0));
    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            char x; cin>>x ;
            if(x=='W') grid[i][j]=0;
            else grid[i][j]=1;
        }
    }
    queue<tuple<int,int,int>> q;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1){
                q.push({i,j,0}); //i,j,time
                vis[i][j]=1;
            }
        }
    }
    int time=0;
    int dir[4][2]={ {1,0}, {-1,0}, {0,-1}, {0,1}};
    while(!q.empty()){
        auto [i,j,t]=q.front(); q.pop();
        
        time=max(time,t);

        for(auto &it:dir){
            int x=i+it[0];
            int y= j + it[1];
            if(x<m && x>=0 && y<n && y>=0 && !vis[x][y] ){
                vis[x][y]=1;
                
                q.push({x,y,t+1});
            }
        }

    }
    cout<<time<<'\n';

    
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