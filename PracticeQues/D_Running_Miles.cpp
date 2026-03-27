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

#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1,0),left(n+1),right(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    int m=INT_MIN;
    left[1]=a[1]+1;right[n]=a[n]-n;
    for(int i=2;i<=n;i++){
       left[i]=max(left[i-1],a[i]+i);
      
    }
    for(int i=n-1;i>=1;i--){
        right[i]=max(right[i+1],a[i]-i);
    }
    int ans=INT_MIN;
    for(int i=2;i<=n-1;i++){
        int res=left[i-1]+a[i]+right[i+1];
        ans=max(ans,res);

    }
    cout<<ans<<'\n';


    
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