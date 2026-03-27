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
int sum=0;vector<int> a;
int n, k,z;
 map<tuple<int,int,int,int>, int> memo;
// vector<vector<vector<int>>>dp;
int f(int pos, int moves, int leftUsed, int lastLeft) {
        if(moves == k) return 0;

        auto key = make_tuple(pos, moves, leftUsed, lastLeft);
        if(memo.count(key)) return memo[key];

        int ans = 0;

        // move right
        if(pos + 1 < n) {
            ans = max(ans, a[pos+1] + f(pos+1, moves+1, leftUsed, 0));
        }

        // move left
        if(pos > 0 && leftUsed < z && lastLeft == 0) {
            ans = max(ans, a[pos-1] + f(pos-1, moves+1, leftUsed+1, 1));
        }

        return memo[key] = ans;
    }

void solve()
{
    sum=0;
    cin >> n >> k>>z;
    a.assign(n,0);read(a);
    if(z==0){
        for(int i=0;i<n && i<=k;i++){
            sum+=a[i];
        }        
        cout<<sum<<'\n';return;
    }
    // z=min(5,k);
    
        memo.clear();
        sum= a[0] + f(0, 0, 0, 0);    
        cout<<sum<<'\n';
    
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