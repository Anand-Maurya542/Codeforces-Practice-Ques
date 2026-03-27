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
    int n, m;
    cin >> n >> m;
    vector<int> a1(n),a2(m);
    read(a1);read(a2);
    int sum1=accumulate(all(a1),0);
    int sum2=accumulate(all(a2),0);
    if(sum1!=sum2){
        cout<<-1<<'\n';
        return;
    }
    int cnt=0,i=0,j=0;
    sum1=0;sum2=0;
    while(i<n || j<m){
        if(sum1==sum2){
            if(sum1!=0) cnt++;
            if(i<n) sum1+=a1[i++];
            if(j<m) sum2+=a2[j++];
        }
        else if(sum1<sum2){
            sum1+=a1[i++];
        }
        else{
            sum2+=a2[j++];
        }
    }
    if(sum1==sum2) cnt++;
    cout<<cnt<<'\n';


    
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