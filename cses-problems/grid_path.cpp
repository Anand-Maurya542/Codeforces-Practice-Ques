// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n"; }
template <typename T>
void read(vector<T>& v) { for (auto& x : v) cin >> x; }

template <typename T>
void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
vector<vector<int>> dp;

int n;
int solve(vector<string>& grid,int i,int j){
    if(i<0 || j<0) return 0;
    if(grid[i][j]=='*') return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=(solve(grid,i-1,j)%MOD+solve(grid,i,j-1)%MOD)%MOD;

}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t = 1;
    // cin >> t;
    // while (t--)
    //     solve();
    cin>>n;
    vector<string> grid(n,string(n,'.'));
    // string temp="";
    dp.assign(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<solve(grid,n-1,n-1)<<'\n';

    return 0;
}