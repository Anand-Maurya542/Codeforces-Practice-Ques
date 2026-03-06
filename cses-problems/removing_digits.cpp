// // Author: Anand Maurya , MNNIT ALLAHABAD

// #include <bits/stdc++.h>
// using namespace std;
// /* ---------- Output Helpers ---------- */
// inline void yes() { cout << "YES\n"; }
// inline void no()  { cout << "NO\n"; }
// template <typename T>
// void read(vector<T>& v) { for (auto& x : v) cin >> x; }

// template <typename T>
// void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

// #define int long long

// using ll = long long;
// const int MOD = 1e9 + 7;
// const long long INF = 1e18;

// vector<int> dp;

// int helper(int n){
//     if(n==0) return 0;
//     if(dp[n]!=-1) return dp[n];
//     int ans=INF;
//     int temp=n;
//     while(temp>0){
//         int d=temp%10;
//         temp/=10;
//         if(d!=0)
//         ans=min(ans,1+helper(n-d));
//     }
//     return dp[n]=ans;
// }
// void solve()
// {
//     int n;
//     cin >> n ;
//     dp.assign(n+1,-1);
//     cout<<helper(n)<<'\n';

    
// }

// int32_t main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }




//iterative
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

void solve()
{
    int n;
    cin >> n;
    vector<int> dp(n+1,INF);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int temp=i;
        while(temp>0){
            int d=temp%10;
            temp/=10;
            if(d!=0){
                dp[i]=min(dp[i],1+dp[i-d]);
            }
        }
    }
    cout<<dp[n]<<'\n';
    
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