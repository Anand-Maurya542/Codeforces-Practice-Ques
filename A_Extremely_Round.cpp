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
//priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
int dir[4][2]={ {1,0},{-1,0}, {0,1}, {0,-1}};      
// vector<vector<int>> adj(n);


vector<int> temp;
bool valid(int x){
    int z=0,d=0;
    while(x>0){
        if(x%10==0) z++;
        d++;
        x/=10;
    }
    return z==d-1;

}
void pre(){
    for(int i=1; i<=999999; i++){
        if(valid(i)) temp.push_back(i);
    }    
}
void solve()
{
    int n;
    cin >> n;
    int cnt=0;
    for(int i=0; i<temp.size(); i++){
        if(temp[i]<=n) cnt++;
        else break;
    }
    cout<<cnt<<"\n";
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    pre();
    while (t--)
        solve();

    return 0;
}