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
    int n=10,m=10;
    int cnt=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            char ch; cin>>ch;
            if(ch=='X'){
                if(i==0 || j==0 || i==9 || j==9) cnt+=1;
                else if(i==1 || j==1 || i==8 || j==8) cnt+=2;
                else if(i==2 || j==2 || i==7 || j==7) cnt+=3;
                else if(i==3 || j==3 || i==6 || j==6) cnt+=4;
                else cnt+=5;
            }
        }
    }
    cout<<cnt<<"\n";
    
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