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
// vector<vector<int>>dp;
// vector<int>dp;
//dp.assign(n, vector<int>(m, -1));
//dp.assign(n, -1);
//priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
int dir[4][2]={ {1,0},{-1,0}, {0,1}, {0,-1}};      
// vector<vector<int>> adj(n);
void solve()
{
    int n;
    cin >> n ;
    vector<int> v(n); read(v);
    vector<int> a,b;
    int num=v[0];
   if(all_of(all(v),[num](int& x){
    return x==num;
   })) {
    cout<<-1<<"\n";
    return;
   }

   int maxi=*max_element(all(v));

   for(int i=0; i<n; i++){
    if(v[i]!=maxi){
        a.push_back(v[i]);
    }else b.push_back(v[i]);
   }
   int l=a.size(), r=b.size();
   if(l==0 || r==0) {
    cout<<-1<<"\n";
    return;
   }
   cout<<l<<' '<<r<<' '<<'\n';
   print(a);
   print(b);

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